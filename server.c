	#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>


void main (){

	int sd , acc  , f;
	char msg [255];
	struct sockaddr_in adresse ;

	sd = (socket(AF_INET , SOCK_STREAM , 0)) ;
	if(sd<0)
		printf("Error of connexion \n");
	

	adresse.sin_family = AF_INET ;
	adresse.sin_port =1230;
	adresse.sin_addr.s_addr = INADDR_ANY;

	bind(sd , (struct sockaddr*)&adresse , sizeof(adresse));

	listen(sd , 5);

	
        while(1){
        	acc= accept(sd ,0 ,0);
        	
        	f = fork();
        	if(f==0){
        		printf("client connected \n");


        while(1){
            read(acc , msg , sizeof(msg));
            printf("Message recieved is : %s\n" , msg);

            msg[strcspn(msg ,"\n")]=0;
        		if (strcmp(msg , "good by")==0){
        			printf("Fin comminucation damnded by client .\n");
        			break;

        }
  
            printf("Enter Your Message: ");
           	fgets(msg , sizeof(msg) ,stdin);
            send(acc , msg , sizeof(msg) , 0);
     
        	
          }

            } 

}
 	close(acc);
	close(sd);
}
