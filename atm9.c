#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <MMsystem.h>


int main(void)
{
	system("color 5");
	int option,pin=9440,confirm_pin,amount,count=0;
	float balance=5000;
	int continue_transaction=1;
	time_t now;
	time(&now);
	
	while(continue_transaction)
	{
		
	printf("\n");
	printf("  %s\n",ctime(&now));
	printf("___________________WELLCOME TO ATM BANK SERVICESES______________________\n\n");
	
	while(pin != confirm_pin)
	{
		printf("Enter  4 digit's confirm pin:\n\n");
		scanf("%d", &confirm_pin);
		if(pin != confirm_pin)
		{
		     Beep(610,500); // here we use two arguments 1 -> frequency and 2-> duration milli seconds
		     
		     PlaySound(TEXT("C:\\Users\\nvarm\\Downloads\\inva_pin.mp3"),NULL,SND_SYNC);
		     	
		     printf("Invalid Pin:\n");	
		}
	
			count++;
		
		if(count == 3 && pin != confirm_pin)
		{
		    printf("Reached maximum limit's! :\n");
		    printf("_________________Thanks For You're time___________________\n");
		    exit(0);	
		}
	}	
	     
	
		printf("#######################___*Available Transaction's*___############################\n");
		printf("\n\n\t\t\t 1 => withdrawl:\n");
		printf("\n\n\t\t\t 2 => Deposit:\n");
		printf(" \n\n\t\t\t 3 => check balance\n");
		printf("\n\n\t\t choose any one option \t\t\t\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			//	printf("You'have selected withdrawl option:\n");
				printf("Enter the amount in multiple of 500:\n");
				scanf("%d", &amount);
				
				   if(amount % 500 != 0)
				   {
				   	printf("\t\t\t\tMake sure the amount will be multiple of 500:\t\t\t\t\n");
				   	return 1;
				   }	
				if(balance < amount)
				{
					printf(" \n\t\tHey! sorry!____Insufficient balance________\t\t\n");
					amount = 1;
					break;
				}
				else
				{
					balance -= amount;
					printf("\n\t\t______You'have withdrawal Rs.%d successfully_______\t\t\n",amount);
					
					PlaySound(TEXT("C:\\Users\\nvarm\\Downloads\\succ_with.mp3"),NULL,SND_SYNC);
					
					printf("\t\t_________Balance = %.2f________\n",balance);
					amount = 1;
					break;
				}
			case 2 :
				//printf("You'have selected deposit option:\n");
				printf("\t\t\t\tEnter the amount to deposit:\t\t\t\n");\
				scanf("%d", &amount);
				if(amount <= 0)
				{
					printf("#__________Invalid amount:________#\n");
				}
				
				balance = balance + amount;
				printf("_________You'have deposit %d  and now you're balance is = %.2f_____\n",amount,balance);
				printf("#_________Thank You!________#:\n");
				amount = 1;
				break;
			case 3 :
			//	printf("You selected check balance option:\n");
				printf("__________Balance = %.2f__________\n",balance);
				break;
		         default:
		         	Beep(610,500);
		         	printf("________Invalid Option:\n________");
		         	
		         	PlaySound(TEXT("C:\\Users\\nvarm\\Downloads\\17074742785180bge1vz8-voicemaker.in-speech.mp3"),NULL,SND_SYNC);
		         	
		         	printf("###################_________Thanks For You're time_________________###################\n");
		         	
   		}
   		printf("____________Do You Want To Continue press 1 for Yes ,0 for No ___________\n");
   		scanf("%d", &continue_transaction);
         }
	
	return 0;
}
	
	
	
