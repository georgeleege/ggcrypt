#include "substitution.h"
#include <string>

std::string caesar_shift(int key, std::string text) {
  std::string output = "";
  // modulo with different signs is not standardized
  key = (95 + key % 95) % 95;
  for (auto i = 0; i < text.size(); ++i) {
    unsigned char shifted = (text[i] - ' ' + key) % 95 + ' ';
    output += shifted;
  }
  return output;
}

std::string vigenere_encrypt(std::string key, std::string plaintext) {
  if (key.size() == 0) {
    return plaintext;
  }
  std::string output = "";
  auto key_pos = 0;
  for (auto i = 0; i < plaintext.size(); ++i) {
    char p = plaintext[i] - ' ';
    char k = key[key_pos] - ' ';
    char shifted = (p + k) % 95 + ' ';
    ++key_pos;
    key_pos %= key.size();
    output += shifted;
  }
  return output;
}

std::string vigenere_decrypt(std::string key, std::string ciphertext) {
  if (key.size() == 0) {
    return ciphertext;
  }
  std::string output = "";
  auto key_pos = 0;
  for (auto i = 0; i < ciphertext.size(); ++i) {
    char c = ciphertext[i] - ' ';
    char k = key[key_pos] - ' ';
    // modulo with different signs is not standardized
    char shifted = (95 + (c - k)) % 95 + ' ';
    ++key_pos;
    key_pos %= key.size();
    output += shifted;
  }
  return output;
}

std::string autokey_encrypt(std::string key, std::string plaintext) {
  if (key.size() == 0) {
    return plaintext;
  }
  auto autokey = key + plaintext;
  return vigenere_encrypt(autokey, plaintext);
}

std::string autokey_decrypt(std::string key, std::string ciphertext) {
  if (key.size() == 0) {
    return ciphertext;
  }

  // can do the following recursively, but maybe not great for small keys
  std::string output = "";

  auto c_pos = 0;
  for (auto i = 0; i < key.size() && i < ciphertext.size(); ++i) {
    char c = ciphertext[i] - ' ';
    char k = key[i] - ' ';
    // modulo with different signs is not standardized
    char shifted = (95 + (c - k)) % 95 + ' ';
    ++c_pos;
    output += shifted;
  }
  while (c_pos < ciphertext.size()) {
    char c = ciphertext[c_pos] - ' ';
    char k = ciphertext[c_pos - key.size()] - ' ';
    // modulo with different signs is not standardized
    char shifted = (95 + (c - k)) % 95 + ' ';
    ++c_pos;
    output += shifted;
  }

  return output;
}
