/******************************************************************************
*
* File Name: adminsealops.cpp
* Authors:   Gonçalo Mestre & Carolina Zerbes & Rui Pedro Silva
* Revision:  07 Dec 2019
*
* NAME
*  adminsealops - Declaration of the functions needed for the admin operations
* that have operations using the SEAL MICROSOFT library.
*
* DESCRIPTION
*  This file implements important functions for the election system, including
* the generation of the election keys, the creation of the trustees and the
* encryption of the vector of the voters weights
*
*****************************************************************************/
#include "adminsealops.h"

using namespace std;
using namespace seal;


/******************************************************************************
 * generate_election_keys()
 *
 * Arguments: none
 * Returns: none
 *
 * Description: Generates the chosen context and the keys for this context.
 *  Then this saves the generated keys to the corresponding files and puts each
 *  file in the right place.
 *
 *****************************************************************************/
void generate_election_keys(){
  // Defining the context and parameters for the key generation
  EncryptionParameters parms(scheme_type::BFV);
  size_t poly_modulus_degree = 8192;
  parms.set_poly_modulus_degree(poly_modulus_degree);
  parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
  parms.set_plain_modulus(PlainModulus::Batching(poly_modulus_degree, 20));
  auto context = SEALContext::Create(parms);
  PublicKey election_public_key;
  SecretKey election_secret_key;

  // Key Generation
  KeyGenerator keygen(context);
  election_public_key = keygen.public_key();
  election_secret_key = keygen.secret_key();

  // Saving the keys to files
  ofstream publickeyfile;
  publickeyfile.open("election_public_key.txt", ofstream::binary);
  election_public_key.save(publickeyfile);
  publickeyfile.close();
  ofstream secretkeyfile;
  secretkeyfile.open("election_secret_key.txt", ofstream::binary);
  election_secret_key.save(secretkeyfile);
  secretkeyfile.close();

  // Moving the files to the right place
  system("sudo mkdir ../Proj/Keys");
  system("sudo cp election_public_key.txt ../Proj/Keys");
  system("sudo rm -r election_public_key.txt");
  system("sudo cp election_secret_key.txt ../Proj/Keys");
  system("sudo rm -r election_secret_key.txt");
}

/******************************************************************************
 * breaksecretkey()
 *
 * Arguments: none
 * Returns: none
 *
 * Description: MEXE NESTA BONZAS USAR O SHAMIR
 * GERAR CHAVE SIMETRICA, NAO PODE TER MAIS DE 64 BYTES, USAR OPENSSL
 * SABER COMO ENCRIPTAR COM ESTA CHAVE E DESENCRIPTAR
 *
 *****************************************************************************/
void breaksecretkey(){
  // Setting the parameters for the key load
  EncryptionParameters parms(scheme_type::BFV);
  size_t poly_modulus_degree = 8192;
  parms.set_poly_modulus_degree(poly_modulus_degree);
  parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
  parms.set_plain_modulus(PlainModulus::Batching(poly_modulus_degree, 20));
  auto context = SEALContext::Create(parms);

  uint8_t secretkey[10000];
  sss_Share shares[255];
  // Getting the secret key from its file
  ifstream skey;
  skey.open("../Proj/Keys/election_secret_key.txt", ios::binary);
  SecretKey election_secret_key;
  election_secret_key.load(context, skey);
  skey.close();

  memcpy (&secretkey, &election_secret_key, sizeof(election_secret_key));
  sss_create_shares(shares, secretkey, 255, 255);
  system("cd .. && sudo mkdir Proj/Trustees");
  for(int i=0; i < 255; i = i + 1){
    ofstream sharefile;
    string aaa = "sharefile";
    string txt = ".txt";
    string mv1 = "sudo mv ";
    string mv2 = " ../Proj/Trustees";
    aaa.append(to_string(i + 1));
    aaa.append(txt);

    sharefile.open(aaa, ofstream::binary);
    sharefile.write((char*)shares[i], sizeof(shares[i]));
    sharefile.close();

    mv1.append(aaa);
    mv1.append(mv2);
    system(mv1.c_str());
  }

}


/******************************************************************************
 * weight_encryption()
 *
 * Arguments: - The number of voters on this election
 *            - Array of integers with the weights for each voter
 * Returns: none
 *
 * Description: Encrypts the weights array and saves the encrypted data in a
 *  file, then saves the file on the right place
 *
 *****************************************************************************/
void weight_encryption(int nvoters, int* weights){
  // Setting the parameters for the encryption
  EncryptionParameters parms(scheme_type::BFV);
  size_t poly_modulus_degree = 8192;
  parms.set_poly_modulus_degree(poly_modulus_degree);
  parms.set_coeff_modulus(CoeffModulus::BFVDefault(poly_modulus_degree));
  parms.set_plain_modulus(PlainModulus::Batching(poly_modulus_degree, 20));
  auto context = SEALContext::Create(parms);

  // Getting the public key from the corresponding file
  ifstream pkey;
  pkey.open("../Proj/Keys/election_public_key.txt", ios::binary);
  PublicKey election_public_key;
  election_public_key.load(context, pkey);
  pkey.close();


  // Setting the encryption process
  Encryptor encryptor(context, election_public_key);
  BatchEncoder batch_encoder(context);
  Plaintext plainvector;
  Ciphertext encrypted_matrix;
  size_t slot_count = batch_encoder.slot_count();
  vector<uint64_t> pod_matrix(slot_count, 0ULL);

  // Casting the weights to a vector of the necessary type
  for(int i=0; i < nvoters; i = i + 1)
    pod_matrix[i] = (uint64_t) weights[i];

  // Encoding, encrypting and save the data to a file
  batch_encoder.encode(pod_matrix, plainvector);
  encryptor.encrypt(plainvector, encrypted_matrix);
  ofstream weights_file;
  weights_file.open("weights_file.txt", ofstream::binary);
  encrypted_matrix.save(weights_file);
  weights_file.close();

  // Moving the file to the right place
  system("sudo cp weights_file.txt ../Proj/Tally");
  system("sudo rm -r weights_file.txt");
}
