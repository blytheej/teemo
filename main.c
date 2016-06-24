#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define fopen fopen_s
#include <string.h>

main() {

	int a=0;
	
	


	while (a>=0&&a<10)
	{

	

	//show menu
		printf("0. Read data files\n1. display statistics\n2. Top 5 most tweeted words\n3. Top 5 most tweeted users 4. Find users who tweeted a word\n5. Find all people who are friends of the above users\n6. Delete all mentions of a word\n7. Delete all users who mentioned a word\n8. Find strongly connected components\n9. Find shortest path from a given user\n99. Quit\nSelect Menu:");
	
		scanf_s("%d", &a);
	//show menu
	
	//1 read data files
		if (a == 0) {

			char u1[30], u2[50], u3[30], *ptr;

			printf("0.Read Data File\n\n");
			printf("Loading...Please wait.\n");

			//open file
			FILE *friend, *user, *word;
			fopen(&friend, "friend.txt", "r");
			fopen(&user, "user.txt", "r");
			fopen(&word, "word.txt", "r");


			//open file

			int f = 0, u = 0, w = 0;



			while (ptr = fgets(u1, 30, user)) {
				if (!(ptr = fgets(u2, 50, user))) break;
				if (!(ptr = fgets(u3, 30, user))) break;
				ptr = fgets(u2, 50, user);
				u++;
			}

			while (ptr = fgets(u1, 30, friend)) {
				if (!(ptr = fgets(u2, 50, friend))) break;
				ptr = fgets(u2, 50, friend);
				f++;
			}
			while (ptr = fgets(u1, 30, word)) {
				if (!(ptr = fgets(u2, 50, word))) break;
				if (!(ptr = fgets(u3, 50, word))) break;
				ptr = fgets(u2, 50, word);
				w++;

			}


			printf("Total users : %d\n", u);
			printf("Total friendship records : %d\n", f);
			printf("Total tweets : %d\n\n", w);
			fclose(friend); fclose(user); fclose(word);
		}

		//1

		//4	find users who tweeted a word
		else if (a == 4) {
			printf("4. Find users who tweeted a word!\n");
			printf("Write the word to search:  ");
			char search[10000];
			getchar();
			gets(search);
			

			char u1[100], u2[100], u3[100], u4[11], *ptr;
			char w1[100], w2[100], w3[10000], w4[10];
			int n = 0;

			printf("결과:   \n");
			//open file
			FILE  *word;
			fopen(&word, "word.txt", "r");
			//open file
			while (ptr = fgets(w1, 99, word)) {
				fgets(w2, 99, word);
				fgets(w3, 10000, word);
				fgets(w4, 11, word);


				if (strstr(w3, search)) {
					FILE  *user;
					fopen(&user, "user.txt", "r");
					while (ptr = fgets(u1, 99, user)) {
						ptr = fgets(u2, 99, user);
						ptr = fgets(u3, 99, user);
						ptr = fgets(u4, 10, user);

						if (strcmp(u1, w1) == 0) {
							printf("%s\n", u3);		
						}
					}
					fclose(user);
					n++;
				}
			}
			printf("%d 개의 결과!\n\n", n);
			fclose(word);
		}
		//4

		else if (a == 99)
			break;

		
	}
}