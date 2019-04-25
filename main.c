#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGE_LEN 300
#define ALPHABET_LEN 26
#define a_ASCII 97
#define z_ASCII 122
#define A_ASCII 65
#define Z_ASCII 90

// known frequencies for English language, 0.0855 represents for A, 0.0160 for B etc.
double known_freq[] = { 0.0855, 0.0160, 0.0316, 0.0387, 0.1210, 0.0218, 0.0209, 0.0496, 0.0733, 0.0022, 0.0081,
						0.0421, 0.0253, 0.0717, 0.0747, 0.0207, 0.0010, 0.0633, 0.0673, 0.0894, 0.0268, 0.0106, 0.0183, 0.0019,
						0.0172, 0.0011
};

/*
	Function that ask user to input message and key and based on that perform rotation encription
	no params
	no retrun value
	limitations: input message can't be longer then MESSAGE_LEN, key input must be int
*/
void encription_rotation()
{
	char message[MESSAGE_LEN]; // plain text message variable
	char cipher[MESSAGE_LEN];// cipher text message variable
	int tmpVal; // help variable for calculations
	int key; // variable that holds key, rotation value
	int i; // loop variable for indexing

	fgets(message, MESSAGE_LEN, stdin); // flush stdin, read left \n sign

	printf("Enter the message text (UPPERCASE): ");
	fgets(message, MESSAGE_LEN, stdin); // read line of text - message

	printf("Enter key - rotation amount [0..25]: ");
	scanf("%d", &key); // read shift value

	for (i = 0; i < strlen(message); i++) // for each letter in message
	{
		if ((message[i] >= a_ASCII) && (message[i] <= z_ASCII)) // if letter is lowercase
		{
			message[i] = message[i] - 32; // translate it to UPPERCASE
		}

		if ((message[i] >= A_ASCII) && (message[i] <= Z_ASCII)) // if it is a letter, exclude white spaces, numbers etc..
		{
			tmpVal = message[i] + key; // shift letter right

			if (tmpVal > Z_ASCII) // if letter is beyond 'Z'
				cipher[i] = tmpVal - ALPHABET_LEN; // substract from begining
			else if (tmpVal < A_ASCII)
				cipher[i] = tmpVal + ALPHABET_LEN; // if letter is before 'A'
			else
				cipher[i] = tmpVal; // substract from begining

		}
		else
		{
			cipher[i] = message[i]; // if character is not letter just copy
		}
	}

	cipher[i] = '\0'; // add null terminator at the and to make valid string
	printf("Cipher text: %s\n", cipher); // print cipher text
}

/*
	Function that ask user to input message and key and based on that perform rotation decription
	no params
	no retrun value
	limitations: input cipher can't be longer then MESSAGE_LEN, key input must be int
*/
decription_rotation_with_key()
{
	char message[MESSAGE_LEN]; // plain text message variable
	char cipher[MESSAGE_LEN];// cipher text message variable
	int tmpVal; // help variable for calculations
	int key; // variable that holds key, rotation value
	int i; // loop variable for indexing

	fgets(message, MESSAGE_LEN, stdin); // flush stdin, read left \n sign

	printf("Enter the cipher text (UPPERCASE): ");
	fgets(cipher, MESSAGE_LEN, stdin); // read line of text - cipher

	printf("Enter key - rotation amount [0..25]: ");
	scanf("%d", &key); // read shift value

	for (i = 0; i < strlen(cipher); i++) // for each letter in cipher
	{
		if ((cipher[i] >= a_ASCII) && (cipher[i] <= z_ASCII)) // if letter is lowercase
		{
			cipher[i] = cipher[i] - 32; // translate it to UPPERCASE
		}

		if ((cipher[i] >= A_ASCII) && (cipher[i] <= Z_ASCII)) // if it is a letter, exclude white spaces, numbers etc..
		{
			tmpVal = cipher[i] - key; // shift letter left

			if (tmpVal > Z_ASCII) // if letter is beyond 'Z'
				message[i] = tmpVal - ALPHABET_LEN; // substract from begining
			else if (tmpVal < A_ASCII)
				message[i] = tmpVal + ALPHABET_LEN; // if letter is before 'A'
			else
				message[i] = tmpVal; // substract from begining

		}
		else
		{
			message[i] = cipher[i]; // if character is not letter just copy
		}
	}

	message[i] = '\0'; // add null terminator at the and to make valid string
	printf("Message text: %s\n", message); // print message plain text

}


/*
	Function that ask user to input message and key and based on that perform supstitute encription
	no params
	no retrun value
	limitations: input message can't be longer then MESSAGE_LEN, key input must be 26 letters
*/
void encription_substitution()
{
	char message[MESSAGE_LEN]; // plain text message variable
	char cipher[MESSAGE_LEN];// cipher text message variable
	char key[ALPHABET_LEN + 1]; // variable that holds key, supstitution array +1 for \0
	int tmpVal; // help variable for calculations
	int i; // loop variable for indexing

	fgets(message, MESSAGE_LEN, stdin); // flush stdin, read left \n sign

	printf("Enter the message text (UPPERCASE): ");
	fgets(message, MESSAGE_LEN, stdin); // read line of text - message

	printf("Enter key - supstitution array UPPERCASE of length 26 (eg. QWERTYUIOPASDFGHJKLZXCVBNM): ");
	scanf("%s", &key); // read supstitution array

	for (i = 0; i < strlen(message); i++) // for each letter in message
	{
		if ((message[i] >= a_ASCII) && (message[i] <= z_ASCII)) // if letter is lowercase
		{
			message[i] = message[i] - 32; // translate it to UPPERCASE
		}

		if ((message[i] >= A_ASCII) && (message[i] <= Z_ASCII)) // if it is a letter, exclude white spaces, numbers etc..
		{
			tmpVal = message[i] - A_ASCII; // make values start from 0 as index for key table

			cipher[i] = key[tmpVal]; // supstitute from key table

		}
		else
		{
			cipher[i] = message[i]; // if character is not letter just copy
		}
	}

	cipher[i] = '\0'; // add null terminator at the and to make valid string
	printf("Cipher text: %s\n", cipher); // print cipher text

}
