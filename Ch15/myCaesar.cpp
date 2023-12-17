/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Encryption and Decryption (based on pr15-08.cpp)
 * Program description: This program demonstrates pure virtual functions and basic encryption
 * Date: 4-14-2021
*************************************************************************************************/ 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

enum cryptType {Encrypt=1, Decrypt=2};

class Encryption
{
   protected:
      ifstream inFile;
      ofstream outFile;
   public:
      Encryption(const string& inFileName, const string& outFileName);
      virtual  ~Encryption();
      // Pure virtual function
      virtual char transform(char ch, int shiftKey, int encryptOrDecrypt) const = 0;
      // Do the actual work.
      virtual void encrypt(int k) final;
      virtual void decrypt(int k, int encryptOrDecrypt, bool) final;
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(const string& inFileName, const string& outFileName)
{
   inFile.open(inFileName);
   outFile.open(outFileName);
   if (!inFile)
   {
      cout << "The file " << inFileName << " cannot be opened.";
      exit(1);
   }
   if (!outFile)
   {
      cout << "The file " << outFileName << " cannot be opened.";
      exit(1);
   }
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption()
{
   inFile.close();
   outFile.close();
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//***************************************************** 
void Encryption::encrypt(int key)
{
   char ch;
   char transCh;
   inFile.get(ch);
   while (!inFile.fail())
   {
      transCh = transform(ch, key, Encrypt);
      outFile.put(transCh);
      inFile.get(ch);
   }
}
void Encryption::decrypt(int key, int encryptOrDecrypt, bool displayOnly)
{
   char ch;
   char transCh;
   inFile.get(ch);
   while (!inFile.fail())
   {
      transCh = transform(ch, key, Decrypt);
      //outFile.put(transCh);
      cout << transCh;
      inFile.get(ch);
   }
}

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption : public Encryption 
{
public:
   char transform(char ch, int shiftKey, int encryptOrDecrypt) const override
   {
      //int shiftKey = 1;
      if (encryptOrDecrypt == 1)
         return ch + shiftKey;
      else if (encryptOrDecrypt == 2)
         return ch - shiftKey;
      else
         exit(-1);
   }
   SimpleEncryption(const string& inFileName, const string& outFileName)
      : Encryption(inFileName, outFileName)
   {
   }
};

int main()
{
   int choice;
   enum menuChoices
   {
      EncryptFile = 1,
      EncryptInput = 2,
      DecryptFile = 3,
      Decrypt_DisplayOnly = 4,
      Quit = 0
   };
   string inFileName, outFileName;
   int key;
   do
   {
      cout << "1.) Encrypt a text file" << endl
           << "2.) Encrypt an input to a file" << endl
           << "3.) Decrypt a text file (requires that this encrypted it)" << endl
           << "4.) Decrypt file content but only display here (not decrypt & overwrite)" << endl
           << "0.) Quit" << endl;

      cin >> choice;
      while (!cin || choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0)
      {
         cin.clear();
         cin.ignore();
         cout << " Invalid input." << endl;
         cin >> choice;
      }

      switch (choice)
      {
      case EncryptFile:
      {
         cout << "Enter name of file to encrypt: ";
         cin >> inFileName;
         cout << "Enter cipher key: ";
         cin >> key;

         cout << "Enter name of file to receive the encrypted text: ";
         cin >> outFileName;
         SimpleEncryption obfuscate(inFileName, outFileName);
         obfuscate.encrypt(key);
         cout << "Done." << endl;
         break;
      }
      case EncryptInput:
      {
         cout << "not available yet" << endl;
         break; // not finished yet....

         string modifyThis;
         cout << "Enter a word, phrase, or whatever you want to encrypt:" << endl;
         getline(cin, modifyThis);

         cout << "Enter name of file to receive "
              << "the encrypted text: ";
         cin >> outFileName;
         SimpleEncryption obfuscate(inFileName, outFileName);
         obfuscate.encrypt(key);

         cout << "Done." << endl;
         break;
      }
      case DecryptFile:
      {
         cout << "Enter name of file to decrypt: ";
         cin >> inFileName;
         cout << "Enter cipher key: ";
         cin >> key;

         cout << "Enter name of file to receive "
              << "the decrypted content: ";
         cin >> outFileName;
         SimpleEncryption reveal(inFileName, outFileName);
         reveal.decrypt(key, Decrypt, false);
         break;
      }
      case Decrypt_DisplayOnly:
      {
         cout << "Enter name of file to decrypt: ";
         cin >> inFileName;
         cout << "Enter cipher key: ";
         cin >> key;

         SimpleEncryption reveal(inFileName, outFileName);
         reveal.decrypt(key, Decrypt, true);
         cout << endl;
         break;
      }

      default:
         break;
      }

   } while (choice != 0);

   cout << "End of program.";
   return 0;
}