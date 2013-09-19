/*
  Name: PCIA.exe
  Copyright: Todo os direitos reservados 2008
  Author: Ramon Silva de Barros
  Date: 07/12/08 14:11
  Description: Programa destinado para estudo da Inteligencia Artificial
*/

#define TRUE    1
#define FALSE   0

#include <string.h>
#include <iostream>
#include <istream>
//#include <stdlib.h>
//#include <stdio.h>
#include <time.h>
#include <fstream>
//#include <windows.h>
#include <conio.h>
//#include "file.h"


using namespace std;

void Entrada_dados();
void Saida_dados();
void Analise();
void ASV();	
//void Help();
void Converte_MM();
void Comandos();
void PesquisaATXT();                          // Pesquisa Arquivo TXT
void Pesquisa_ACTXT();                         // Pesquisa Arquivo Comandos TXT 
void Gravando_arquivo();
//void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
int Gravando_arquivo_Comandos(char Comando[20],int Num);
//void Sair_sistema();
          
     char aux1[40],aux_pl[40],letra[2],palavra[20],final[2]="\0",SYSTEMA[]="[SYSTEM]";
	 int PL=0; 
	 struct COMANDOS {
		string DUVIDA,ISTO,AQUILO,SAIR,HELP,IGUAL,DIFER;
		string NAO,SIG,OK;
		char CMD[20];
		char COMANDO[20];
		int NUM;
		}COMANDOS;
		
int main()
{
    COMANDOS.DUVIDA="?";
    COMANDOS.ISTO="[<-]";
    COMANDOS.AQUILO="[->]";
    COMANDOS.SAIR="[CLOSE]";
    COMANDOS.HELP="[HELP]";
    COMANDOS.IGUAL="[==]";
    COMANDOS.DIFER="[!=]";
    COMANDOS.NAO="[NO]";
    COMANDOS.SIG="{SIG}";
    COMANDOS.OK="[OK]";
    
cout<<" PPPPPPPPPPPPPPPPP           CCCCCCCCCCCCCIIIIIIIIII               AAA                "<<endl;
cout<<" P::::::::::::::::P       CCC::::::::::::CI::::::::I              A:::A               "<<endl;
cout<<" P::::::PPPPPP:::::P    CC:::::::::::::::CI::::::::I             A:::::A              "<<endl;
cout<<" PP:::::P     P:::::P  C:::::CCCCCCCC::::CII::::::II            A:::::::A             "<<endl;
cout<<"   P::::P     P:::::P C:::::C       CCCCCC  I::::I             A:::::::::A            "<<endl;
cout<<"   P::::P     P:::::PC:::::C                I::::I            A:::::A:::::A           "<<endl;
cout<<"   P::::PPPPPP:::::P C:::::C                I::::I           A:::::A A:::::A          "<<endl;
cout<<"   P:::::::::::::PP  C:::::C                I::::I          A:::::A   A:::::A         "<<endl;
cout<<"   P::::PPPPPPPPP    C:::::C                I::::I         A:::::A     A:::::A        "<<endl;
cout<<"   P::::P            C:::::C                I::::I        A:::::AAAAAAAAA:::::A       "<<endl;
cout<<"   P::::P            C:::::C                I::::I       A:::::::::::::::::::::A      "<<endl;
cout<<"   P::::P             C:::::C       CCCCCC  I::::I      A:::::AAAAAAAAAAAAA:::::A     "<<endl;
cout<<" PP::::::PP            C:::::CCCCCCCC::::CII::::::II   A:::::A             A:::::A    "<<endl;
cout<<" P::::::::P             CC:::::::::::::::CI::::::::I  A:::::A               A:::::A   "<<endl;
cout<<" P::::::::P               CCC::::::::::::CI::::::::I A:::::A                 A:::::A  "<<endl;
cout<<" PPPPPPPPPP                  CCCCCCCCCCCCCIIIIIIIIIIAAAAAAA                   AAAAAAA "<<endl;
cout<<"\n\n";          
cout<<"                                1111111                 000000000        "<<endl;
cout<<"                                1::::::1               00:::::::::00     "<<endl;
cout<<"                               1:::::::1             00:::::::::::::00   "<<endl;
cout<<"                               111:::::1            0:::::::000:::::::0  "<<endl;
cout<<" vvvvvvv           vvvvvvv        1::::1            0::::::0   0::::::0  "<<endl;
cout<<"  v:::::v         v:::::v         1::::1            0:::::0     0:::::0  "<<endl;
cout<<"   v:::::v       v:::::v          1::::1            0:::::0     0:::::0  "<<endl;
cout<<"    v:::::v     v:::::v           1::::l            0:::::0 000 0:::::0  "<<endl;
cout<<"     v:::::v   v:::::v            1::::l            0:::::0 000 0:::::0  "<<endl;
cout<<"      v:::::v v:::::v             1::::l            0:::::0     0:::::0  "<<endl;
cout<<"       v:::::v:::::v              1::::l            0:::::0     0:::::0  "<<endl;
cout<<"        v:::::::::v               1::::l            0::::::0   0::::::0  "<<endl;
cout<<"         v:::::::v             111::::::111         0:::::::000:::::::0  "<<endl;
cout<<"          v:::::v              1::::::::::1 ...... 00:::::::::::::00   "<<endl;
cout<<"           v:::v               1::::::::::1 .::::.   00:::::::::00     "<<endl;
cout<<"            vvv                111111111111 ......     000000000       "<<endl;
cout<<"\n\n";               
    cout <<"\nO computador nao sabe nenhuma palavra tente ensina-lo."<<endl;
    cout <<"\nEm caso de duvida digite [HELP] para ajuda ou acesse o manual."<<endl;
    cout <<"Para sair do sistema digite - [CLOSE]."<<endl;
    cout <<"! ** ATENCAO ** ! No decorrer do programa o PCIA pode modificar\n";
    cout <<" os comandos por outros dependendo da informacao que recebe\n";
    cout <<"Desenvolvedor: Ramon Barros. rbarros_@hotmail.com"<<endl;
    cout <<"CURSO EM CASA APRENDENDO SOZINHO"<<endl;
  
    Entrada_dados();
    system("PAUSE");     
    return EXIT_SUCCESS;
}

// Entrada de dados. 
void Entrada_dados()
{
     cout<<SYSTEMA<<COMANDOS.DUVIDA<<endl;                          //Imprime [SYSTEM]? 
     cin >> aux_pl;                                           // Var. auxiliar que guarda a palavra ou letra.
     //Comandos();
     Analise();                                            // Vai para a funcao Analise.
}

// Funcao Analise, verifica se o que foi digitado e uma letra ou palavra.
void Analise()
{                                                       //f=strlen(aux_pl);
     int x,z;
     for(x=0;x<2;x++)                                   //loop para percorrer a variavel aux_pl
     {
          if(aux_pl[x]<=1)                                // se var. aux_pl contem 1 caracteres = letra
          {
              strcpy(letra,aux_pl);                       // copia aux_pl para letra
              strcat(letra,final);                      // acrescenta "\0" no final da letra
              cout <<COMANDOS.DUVIDA<<letra<<endl;               // imprime ?letra
              PL = 1;
			  ASV();
              //PesquisaLTXT();                           //Pesquisa arquivo letras.txt 
          }
     }
     for(z=0;z<2;z++)                                   //loop para percorrer a variavel aux_pl
     {
          if(aux_pl[z]>2)                                 // se var. aux_pl contem acima de 3 caracteres = palavra
          {
               strcpy(palavra,aux_pl);                    //copia aux_pl para palavra
               strcat(palavra,final);                   // acrescenta "\0" no final da palavra
               cout <<COMANDOS.DUVIDA<<palavra<<endl;            //imprime ?palavra
               PL = 2;
			   ASV();
               //PesquisaPTXT();                          //Pesquisa arquivo palavras.txt
          }
     }
}

void ASV()                                             // Artigo Substantivo ou Verbo
{
    int ASV_ASV=0;                                      // Variavel para CASE do switch
     char aux_ASV[20];
     string aux_nosig;
     char A[]="[";
     char B[]="]";                                // Variavel auxiliar para 
     //string AR="[ARTIGO]",SU="[SUBS]",VE="[VERBO]";
     aux_nosig=COMANDOS.NAO+COMANDOS.SIG; // Concatena as strings ficando NAO+SIG = "[NO]{SIG}"
     if (PL == 1) 
     {
     cout <<letra<<COMANDOS.AQUILO<<COMANDOS.DUVIDA<<endl;      // Imprime "Letra" [->] ? 
     cin>>COMANDOS.CMD;
        Converte_MM();     
     }
      if (PL == 2) 
     {
     cout <<palavra<<COMANDOS.AQUILO<<COMANDOS.DUVIDA<<endl;      // Imprime "Palavra" [->] 
     cin>>COMANDOS.CMD;
       Converte_MM();
     }
     
     strcpy(aux_ASV,A);                       // copia aux_pl para letra
     strcat(aux_ASV,COMANDOS.CMD);
     strcat(aux_ASV,B);
     strcpy(COMANDOS.CMD,aux_ASV);
     ASV_ASV++;
     
     if (PL == 1) 
     {
     cout <<letra<<COMANDOS.ISTO<<COMANDOS.CMD<<endl;      // Imprime "Letra" [<-] [CMD] 
     PesquisaATXT();
     }
      if (PL == 2) 
     {
     cout <<palavra<<COMANDOS.ISTO<<COMANDOS.CMD<<endl;      // Imprime "Palavra" [<-] [CMD] 
     PesquisaATXT();
     }
     
}
void Converte_MM()
{
    int cmd[100];
    for (int i = 0; i < 20; i++)
    {
        COMANDOS.COMANDO[i]=COMANDOS.CMD[i];
        cmd[i] = COMANDOS.COMANDO[i];
        if (COMANDOS.COMANDO[i] != ' ')
        {
            if (cmd[i] >= 97 && cmd[i] <= 122)
            {
                 cmd[i] -= 32;
            }
        }
        COMANDOS.COMANDO[i] = cmd[i];
    }
}

void PesquisaATXT()                                // Verifica se já existe a letra
{
    char MEMO[]="[MEMO]";
   char aux4[2];
   char A[]=".pci";
   char arquivo[20];
     strcpy(arquivo,COMANDOS.CMD);                       // copia aux_pl para letra
     strcat(arquivo,A);
     ifstream in3(arquivo);                   // Abre arquivo para leitura
     while(in3>>aux4)
     {         
          cout<<MEMO<<COMANDOS.IGUAL<<" "<<aux4<<"\n ";
          if(strcmp(aux4,letra)==0)                    //Verifica se ja existe a palavra no arquivo.
          {
               cout<<COMANDOS.CMD<<COMANDOS.IGUAL<<letra<<endl;     //Caso estiver imprime
               Entrada_dados();                              //Retorna a Entrada de dados.
          }
           if(strcmp(aux4,palavra)==0)                    //Verifica se ja existe a palavra no arquivo.
          {
               cout<<COMANDOS.CMD<<COMANDOS.IGUAL<<palavra<<endl;     //Caso estiver imprime
               Entrada_dados();                              //Retorna a Entrada de dados.
          }
     }
     in3.close();                                           //fecha arquivo in
     Gravando_arquivo();                			        //Grava a palavra informada no arquivo Palavras.txt   
}         

void Gravando_arquivo()                  				    //Grava palavra informada
{
     char A[]=".pci";
     char arquivo[20];
     strcpy(arquivo,COMANDOS.COMANDO);                      // copia aux_pl para letra
     strcat(arquivo,A);
     if (PL == 1) 
     {
      ofstream arquivo_ATXT(arquivo,ios::out|ios::app);       //Abre arquivo para gravacao
      arquivo_ATXT<<letra<<" "<<endl;
      arquivo_ATXT.close();	                                 //Fecha arquivo
     }
      if (PL == 2) 
     {
      ofstream arquivo_ATXT(arquivo,ios::out|ios::app);       //Abre arquivo para gravacao
      arquivo_ATXT<<palavra<<" "<<endl;
      arquivo_ATXT.close();	                                //Fecha arquivo
     }					     
     Pesquisa_ACTXT();             
}

 void Pesquisa_ACTXT()                                // Verifica se já existe a letra
{
   char MEMO[]="[MEMO]";
   char aux5[20];
    char A[]="[";
    char B[]="]";    
   int Num_Comando=0;
   int x;
   
     strcpy(aux5,A);                       // copia aux_pl para letra
     strcat(aux5,COMANDOS.CMD);
     strcat(aux5,B);
   
     ifstream in4("COMANDOS.pci");                 // Abre arquivo para leitura
     while(in4>>aux5) 
     {         
               
           cout<<MEMO<<COMANDOS.IGUAL<<" "<<aux5<<"\n ";
           if(strcmp(aux5,letra)==0)                   //Verifica se ja existe a palavra no arquivo.
           {
               cout<<"COMANDO"<<COMANDOS.IGUAL<<aux5<<endl;    //Caso estiver imprime
               Gravando_arquivo_Comandos(aux5,Num_Comando);                      //Retorna a Entrada de dados.
               }
               Num_Comando++;
     }
     in4.close();
     COMANDOS.NUM++;                                     //fecha arquivo in
     Gravando_arquivo_Comandos(COMANDOS.CMD,COMANDOS.NUM);    //Grava a palavra informada no arquivo Palavras.txt   
}   

int Gravando_arquivo_Comandos(char Comando[20], int Num)
{
     ofstream arquivocomando("COMANDOS.pci",ios::out|ios::app); //Abre arquivo para gravacao
     arquivocomando<<Comando<<" "<<Num<<endl;
     arquivocomando.close();                            //Fecha arquivo
     Entrada_dados();                                      //Retorna a Entrada de dados        
}

/*
void Sair_sistema()
{
     system("PAUSE");
     cout<<"System close.";
     cout<<"\n>        ";
     system("cls");
     Sleep(100);
     cout<<"System close..";
     cout<<"\n>>        ";
     system("cls");
     Sleep(100);
     cout<<"System close...";
     cout<<"\n>>>        ";
       system("cls");
     Sleep(100);
     cout<<"System close....";
     cout<<"\n>>>>        ";  
       system("cls");
     Sleep(100);
     cout<<"System close.....";
     cout<<"\n>>>>>          ";  
       system("cls");
     Sleep(100);
     cout<<"System close......";
     cout<<"\n>>>>>>          ";   
       system("cls");
     Sleep(100);
     cout<<"System close.......";
     cout<<"\n>>>>>>>          ";   
       system("cls");
     Sleep(100);
     cout<<"System close........";
     cout<<"\n>>>>>>>>          ";   
       system("cls");
     Sleep(100);
     cout<<"System close.........";
     cout<<"\n>>>>>>>>>          ";  
       system("cls");
     Sleep(100);
     exit(1);
}
*/

void Help()
{
    char buff[1024];
	
	ifstream fin("Ajuda.txt");
	
    while(fin)
    {
      fin.getline(buff,1024);         
      cout<< buff << "\n";
    }
	fin.close();
}
