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


/*
	Function seek from key table char and return corresonding plain message letter
	params: first - char that need to be decript, second - key table
	return decripted letter
	no limitation
*/
char get_message_letter(char cipher_letter, char* key)
{
	char message_letter; // return corresonding plain letter
	int i; // index for iterating loop

	for (i = 0; i < ALPHABET_LEN; i++) // for each letter in key table
	{
		if (key[i] == cipher_letter) // if letter found return it's index
			break;
	}

	message_letter = i + A_ASCII; // calculate ASCII number from index 0 = A, 1 = B etc.
	return message_letter;
}


/*
	Function that ask user to input message and key and based on that perform supstitute decription
	no params
	no retrun value
	limitations: input cipher can't be longer then MESSAGE_LEN, key input must be 26 letters
*/
void decription_substitution_with_key()
{
	char message[MESSAGE_LEN]; // plain text message variable
	char cipher[MESSAGE_LEN];// cipher text message variable
	char key[ALPHABET_LEN + 1]; // variable that holds key, supstitution array +1 for \0
	int tmpVal; // help variable for calculations
	int i; // loop variable for indexing

	fgets(message, MESSAGE_LEN, stdin); // flush stdin, read left \n sign

	printf("Enter the message text (UPPERCASE): ");
	fgets(cipher, MESSAGE_LEN, stdin); // read line of text - message

	printf("Enter key that is used for encription - supstitution array UPPERCASE of length 26 (eg. QWERTYUIOPASDFGHJKLZXCVBNM): ");
	scanf("%s", &key); // read supstitution array

	for (i = 0; i < strlen(cipher); i++) // for each letter in message
	{
		if ((cipher[i] >= a_ASCII) && (cipher[i] <= z_ASCII)) // if letter is lowercase
		{
			cipher[i] = cipher[i] - 32; // translate it to UPPERCASE
		}

		if ((cipher[i] >= A_ASCII) && (cipher[i] <= Z_ASCII)) // if it is a letter, exclude white spaces, numbers etc..
		{

			message[i] = get_message_letter(cipher[i], key); // supstitute from key table

		}
		else
		{
			message[i] = cipher[i]; // if character is not letter just copy
		}
	}

	message[i] = '\0'; // add null terminator at the and to make valid string
	printf("Message plain text: %s\n", message); // print message text

}

/*
	Function that rotate cipher for passed key
	params: first - cipher message to be rotated, second - rotation value
	return rotated message
*/
char* rotate(char* cipher, int key)
{
	int i;// loop variable for indexing
	int tmpVal; // help variable for calculations
	char message[MESSAGE_LEN]; // rotated text message variable


	for (i = 0; i < strlen(cipher); i++) // for each letter in message
	{
		if ((cipher[i] >= a_ASCII) && (cipher[i] <= z_ASCII)) // if letter is lowercase
		{
			cipher[i] = cipher[i] - 32; // translate it to UPPERCASE
		}

		if ((cipher[i] >= A_ASCII) && (cipher[i] <= Z_ASCII)) // if it is a letter, exclude white spaces, numbers etc..
		{
			tmpVal = cipher[i] + key; // shift letter right

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
	return message;
}

/*
	Function caclulate frequencies of each letter in given text
	param: message text which letters used to calculate frequencies
	return array of frequencies for each letter index 0 for A, index 1 for B etc.
*/
double* frequencies(char *cipher)
{
	int i;// loop variable for indexing
	int tmpVal; // help variable for calculations

	// frequencies array for each letter index 0 for A, index 1 for B etc.
	double freq[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int letter_count = 0; // number of letters in text

	for (i = 0; i < strlen(cipher); i++) // for each letter in message
	{
		if ((cipher[i] >= a_ASCII) && (cipher[i] <= z_ASCII)) // if letter is lowercase
		{
			cipher[i] = cipher[i] - 32; // translate it to UPPERCASE
		}

		if ((cipher[i] >= A_ASCII) && (cipher[i] <= Z_ASCII)) // if it is a letter, exclude white spaces, numbers etc..
		{
			tmpVal = cipher[i] - A_ASCII; // translate ascii values A to Z to values 0 to 25
			freq[tmpVal]++; // count for each letter
			letter_count++;
		}
	}

	for (int i = 0; i < 26; i++) { // calculate frequencies for each letter count
		freq[i] = freq[i] / letter_count;
	}

	return freq;
}

/*
	Function calculates chi squared, that is number that represent how much frequencies of text
	is close to English language
	param: frequencies for which chi is calculated
	return number that represent chi (the lower it is that's closer to English)
*/
double chi_squared(double* curr_freq)
{
	double chi = 0;
	int i;// loop variable for indexing

	for (i = 0; i < ALPHABET_LEN; i++) {
		chi += (curr_freq[i] - known_freq[i]) * (curr_freq[i] - known_freq[i]); // calculation (squared) cause of negative numbers
	}
	return chi;

}

/*
	Function that ask user to input cipher message and based on that perform rotation decription
	witout key, attack is based on statistical calculations of letter frequencies
	no params
	no retrun value
	limitations: input cipher can't be longer then MESSAGE_LEN, key input must be int
				 cipher text that need to be break need to have some decent length
				 the bigger text is the better chances for breaking, cause we can't take
				 statistical data from small text, it's not enough
