/*
  Name: PCIA.exe
  Copyright: Todo os direitos reservados 2008
  Author: Ramon Silva de Barros
  Date: 21/03/08 00:14
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
#include <windows.h>
#include <conio.h> 

using namespace std;

void Entrada_dados();
void Saida_dados();
void Analise_arquivo();
void Analise();
void ASV();

// Função Artigo
void Artigo();

	//Função Artigo Definido
	void A_DEF();	//Definido
	void A_IND();	//Indefinido
	
// Função substantivo
void Subs();

	// Formação
	void S_F_P(); 	// Primitivo
	void S_F_D();	// Derivado
	void S_F_S();	// Simples
	void S_F_C();	// Composto

	// Semantica
	void S_S_CON();	// Concreto
	void S_S_A();		//Abstrato
	void S_S_P();		// Próprio
	void S_S_COL();	// Coletivo

	// Gênero
	void S_GE_B();		// Biforme
	void S_GE_H();		// Heterôgenio
	void S_GE_U();		// Uniforme
	void S_GE_U_E();	// U. Epicenos
	void S_GE_U_C2G();	// U. Comuns de 2 gêneros
	void S_GE_U_S();	// U. Sobrecomuns

	// Numero
	void  S_N_S();		// Simples
	void  S_N_C();		// Composto

	// Grau
	void S_GR_A();		// Analitico
	void S_GR_S();		// Sintético

//Função Verbo
void Verbo();
		
		//Função que localiza a palavra (verbo) que possui a terminação ar,er e ir.
		void V_AR();	
		void V_ER();	
		void V_IR();	
		
		//Função Semanica
		void V_S_T();	//Transitivos
		void V_S_IN();	//Intransitivos
		void V_S_L();	//De Ligação
		void V_S_IM();	//Impessoais
		
		//Funções de conjunção
		void V_C_PC();	//Primeira conjungação
		void V_C_SC();	//Segunda conjungação
		void V_C_TC();	//Terceira conjungação
		
		//Morfologia
		void V_M_R();	//Regulares
		void V_M_I();	//Irregulares
		void V_M_AN();	//Anômalas
		void V_M_D();	//Defectivos
		void V_M_AB();	//Abundantes
		
		//Flexão
		void V_F_N();	//Númeral
		void V_F_P();	//Pessoal
		void V_F_M();	//Modo
		void V_F_T();	//Tempo
	
	
void Help();
void Comandos();
void PesquisaLTXT();
void PesquisaPTXT();
void PesquisaATXT_DEF();
void PesquisaATXT_INDEF();
void PesquisaSTXT();
void PesquisaVTXT();
void Lendo_arquivo_letras();
void Lendo_arquivo_palavras();
void Gravando_arquivo_letras();
void Gravando_arquivo_palavras();
void Gravando_arquivo_Artigo_DEF();
void Gravando_arquivo_Artigo_INDEF();
void Gravando_arquivo_Subs();
void Gravando_arquivo_Verbo();
void Sair_sistema();
          
     char aux_pl[40],letra[2],palavra[20],final[2]="\0",SYSTEMA[]="[SYSTEM]";
	 int PL=0; 
	 struct COMANDOS {
		string DUVIDA,ISTO,AQUILO,SAIR,HELP,IGUAL,DIFER;
		string NAO,SIG,OK;
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
    system("PAUSE");
    Analise_arquivo();
    Entrada_dados();
    system("PAUSE");
    return EXIT_SUCCESS;
}
void Analise_arquivo()
{
     char CP;
     char MEMO[]="[MEMO]";
     char aux_analise_arq[20];
     bool achei_comp;
     bool achei_pc;
     char COMP[]="COMPUTADOR";
     char PC[]="PC";
     char A[]="[";
     char B[]="]";
     ifstream in2("Palavras.txt");                     // Abre arquivo para leitura
     achei_comp=false;
     achei_pc=false;
     while(in2>>aux_analise_arq)
     {         
          cout<<MEMO<<COMANDOS.IGUAL<<" "<<aux_analise_arq;
       if(strcmp(aux_analise_arq,COMP)==0)
       {
          cout <<"\n";
          cout <<SYSTEMA<<COMANDOS.ISTO<<aux_analise_arq<<COMANDOS.IGUAL<<"\n";
          cout <<COMANDOS.OK<<"\n\n";                                   
          achei_comp=true;
          }else{
                cout <<COMANDOS.NAO<<endl;
                }
       if (strcmp(aux_analise_arq,PC)==0)
       {
          cout <<"\n";
          cout <<SYSTEMA<<COMANDOS.ISTO<<aux_analise_arq<<COMANDOS.IGUAL<<"\n";
          cout <<COMANDOS.OK<<"\n\n";  
          achei_pc=true;
          }else{
                cout <<COMANDOS.NAO<<endl;
                }          
     }
     if (( achei_comp==true)&&(achei_pc==true))
     {
          cout <<"\n\n";
          cout << SYSTEMA<<COMANDOS.ISTO<<COMP<<COMANDOS.DUVIDA<<" C(c)\n";
          cout << SYSTEMA<<COMANDOS.ISTO<<PC<<COMANDOS.DUVIDA<<" P(p)\n";
          cout <<" C(c)/P(p)\n";
          cin >> CP;
          if((CP=='C')||(CP=='c'))
          {
                                  
                strcpy(SYSTEMA,A);                       // copia aux_pl para letra
                strcat(SYSTEMA,COMP);
                strcat(SYSTEMA,B);
          }
          if((CP=='P')||(CP=='p'))
          {
                strcpy(SYSTEMA,A);                       // copia aux_pl para letra
                strcat(SYSTEMA,PC);
                strcat(SYSTEMA,B);
          }
          if((CP!='C')&&(CP!='c')&&(CP!='P')&&(CP!='p'))
          {
               cout <<COMP<<"[AND]"<<PC<<COMANDOS.NAO<<COMANDOS.SIG<<SYSTEMA<<"\n";
               cout <<COMANDOS.DUVIDA<<endl;
          }
     }
     else
          {
             if (( achei_comp==true)&&(achei_pc==false))                //Verifica se ja existe a palavra no arquivo.
              {
                cout <<SYSTEMA<<COMANDOS.ISTO<<COMP<<COMANDOS.IGUAL<<"\n";
                cout <<COMANDOS.OK<<"\n\n";                                   
                strcpy(SYSTEMA,A);                       // copia aux_pl para letra
                strcat(SYSTEMA,COMP);
                strcat(SYSTEMA,B);
                }
              if (( achei_comp==false)&&(achei_pc==false))                  //Verifica se ja existe a palavra no arquivo.
              {
                cout <<SYSTEMA<<COMANDOS.ISTO<<PC<<COMANDOS.IGUAL<<"\n";
                cout <<COMANDOS.OK<<"\n\n";                                   
                strcpy(SYSTEMA,A);                       // copia aux_pl para letra
                strcat(SYSTEMA,PC);
                strcat(SYSTEMA,B);
              }
          }
     in2.close();                                      //fecha arquivo in
}

// Entrada de dados. 
void Entrada_dados()
{
     cout<<SYSTEMA<<COMANDOS.DUVIDA<<endl;                          //Imprime [SYSTEM]? 
     cin >>aux_pl;                                           // Var. auxiliar que guarda a palavra ou letra.
     Comandos();
     Analise();                                            // Vai para a funcao Analise.
}
//Comandos do Console
void Comandos()
{
     char YN;
     char A[]="[";
     char B[]="]";
     string PC="PC";
     string COMP="COMPUTADOR";
     if(aux_pl==PC)
     {
          cout << SYSTEMA<<COMANDOS.ISTO<<aux_pl<<COMANDOS.DUVIDA<<"\n";
          cout <<"Y(y)/N(n)\n";
          cin >> YN;
          if((YN=='Y')||(YN=='y'))
          {
                                  
                strcpy(SYSTEMA,A);                       // copia aux_pl para letra
                strcat(SYSTEMA,aux_pl);
                strcat(SYSTEMA,B);
          }
          if((YN=='N')||(YN=='n'))
          {
               cout<<SYSTEMA<<COMANDOS.DUVIDA<<"\n";
          }
     }
      if(aux_pl==COMP)
     {
          cout << SYSTEMA<<COMANDOS.ISTO<<aux_pl<<COMANDOS.DUVIDA<<"\n";
          cout <<"Y(y)/N(n)\n";
          cin >> YN;
          if((YN=='Y')||(YN=='y'))
          {
                                  
                strcpy(SYSTEMA,A);                       // copia aux_pl para letra
                strcat(SYSTEMA,aux_pl);
                strcat(SYSTEMA,B);
          }
          if((YN=='N')||(YN=='n'))
          {
               cout<<SYSTEMA<<COMANDOS.DUVIDA<<"\n";
          }
     }
     if(aux_pl==COMANDOS.SAIR)
       {          
        cout << "\n OK \n";
        Sair_sistema();//_\|/_
       }
     if(aux_pl==COMANDOS.HELP)
     {
       cout << "\n # HELP # \n";
       Help(); // Vai para o menu de ajuda
     }
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
              PesquisaLTXT();                           //Pesquisa arquivo letras.txt
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
               PesquisaPTXT();                          //Pesquisa arquivo palavras.txt
          }
     }
}

// Pesquisa arquivo, verifica se nao tem letra igual
void PesquisaLTXT()
{
     char MEMO[]="[MEMO]";
     char aux3[2];
     ifstream in1("Letras.txt");                        // Abre arquivo para leitura
     while(in1>>aux3)                                   //Verifica se ja existe a palavra no arquivo.
     {
         
         cout<<MEMO<<COMANDOS.IGUAL<<" "<<aux3<<"\n ";
         if(strcmp(aux3,letra)==0)                      // Verifica se a letra informada esta contida no arquivo
         {                                              //se sim entao.
             cout <<"Letra "<<letra<<COMANDOS.IGUAL<<endl;        
             ASV();  //Verifica se Artigo Substantivo ou Verbo            
             Entrada_dados();  //Retorna a Entrada de dados.
         }
     }
     in1.close();
     Gravando_arquivo_letras();

}

void Gravando_arquivo_letras()                          //Grava a letra informada no arquivo Letras.txt             
{
     ofstream arquivol("Letras.txt",ios::out|ios::app);
     arquivol<<letra<<" "<<endl;
     arquivol.close();
     ASV();  //Verifica se Artigo Substantivo ou Verbo
     Entrada_dados();
}

void PesquisaPTXT()                                    //Grava a letra informada no arquivo Palavras.txt 
{
     char MEMO[]="[MEMO]";
     char aux_ptxt[20];
     ifstream in2("Palavras.txt");                     // Abre arquivo para leitura
     while(in2>>aux_ptxt)
     {         
          cout<<MEMO<<COMANDOS.IGUAL<<" "<<aux_ptxt<<"\n ";
          if(strcmp(aux_ptxt,palavra)==0)                  //Verifica se ja existe a palavra no arquivo.
          {
               cout<<"Palavra "<<palavra<<COMANDOS.IGUAL<<endl; //Caso estiver imprime
               ASV();  //Verifica se Artigo Substantivo ou Verbo
               Entrada_dados();                        //Retorna a Entrada de dados.
          }
     }
     in2.close();                                      //fecha arquivo in
     Gravando_arquivo_palavras();                      //Grava a palavra informada no arquivo Palavras.txt   
}

void Gravando_arquivo_palavras()                               //Grava palavra informada
{
     ofstream arquivop("Palavras.txt",ios::out|ios::app); //Abre arquivo para gravacao
     arquivop<<palavra<<" "<<endl;
     arquivop.close();                                     //Fecha arquivo
     ASV();  //Verifica se Artigo Substantivo ou Verbo
     Entrada_dados();                                  //Retorna a Entrada de dados
}

void ASV()                                             // Artigo Substantivo ou Verbo
{
     int ASV_ASV=0;                                      // Variavel para CASE do switch
     string ARSUVE=" ";
     string aux_nosig;                                 // Variavel auxiliar para 
     string AR="[ARTIGO]",SU="[SUBS]",VE="[VERBO]";
     aux_nosig=COMANDOS.NAO+COMANDOS.SIG; // Concatena as strings ficando NAO+SIG = "[NO]{SIG}"
     if (PL == 1) 
     {
     cout <<letra<<COMANDOS.AQUILO<<COMANDOS.DUVIDA<<" ASV "<<endl;      // Imprime "Letra" [->] ? ASV
     cin>>ARSUVE;
     }
      if (PL == 2) 
     {
     cout <<palavra<<COMANDOS.AQUILO<<COMANDOS.DUVIDA<<" ASV "<<endl;      // Imprime "Letra" [->] ? ASV
     cin>>ARSUVE;
     }                   
     if(ARSUVE==AR)
     {
        ASV_ASV=1;
     }
     if(ARSUVE==SU)
     {
        ASV_ASV=2;
     }
     if(ARSUVE==VE)
     {
        ASV_ASV=3;
     }
     if(ARSUVE==aux_nosig)
     {
        ASV_ASV=4;
     }
     if((ARSUVE != AR)&&(ARSUVE != SU)&&(ARSUVE != VE)&&(ARSUVE != aux_nosig))
     {
          cout <<"COMANDO INVALIDO"<<endl;
          ASV_ASV=5;
     }          
         switch(ASV_ASV)
          {
                        case 1:
                             Artigo(); // Passa por parametro o conteudo da variavel AR "[ARTIGO]"
                             break;
                        case 2:
                             //cout<<"SUBS ="<<palavra<<endl;
                             Subs();
                             break;
                        case 3:
                             cout<<"VERBO =\n"<<palavra<<endl;
                            // Verbo();
                             break;
                        case 4:
                             cout <<letra<<COMANDOS.AQUILO<<aux_nosig<<endl;
                             break;
                        case 5:
                             break;
                        default: cout <<COMANDOS.DUVIDA<<endl;
          }
}

void Artigo() //Recebe o parametro passado anteriormente
{
  char YN;
  if (PL == 1) 
  {
   cout <<"\n"<<letra<<COMANDOS.AQUILO<<"[ARTIGO]"<<COMANDOS.DUVIDA<<"\n"; // imprime : "letra” [->][SUBS] ?
   cout <<" Y(y) / N(n) \n";
   cin >> YN;
   if(( YN == 'Y')||(YN == 'y'))
   {
	cout <<letra<<COMANDOS.AQUILO<<"[CLASS]"<<COMANDOS.SIG<<COMANDOS.DUVIDA<<"\n"; // "letra” [->][CLASS][SIG]?
    A_DEF();
    A_IND();
   }
  	if(( YN == 'N')||( YN == 'n'))
	{
	 	cout <<SYSTEMA<<COMANDOS.DUVIDA<<"\n";
		cout << COMANDOS.OK;
	}
   }
   if (PL == 2) 
  {
   cout <<"\n"<<palavra<<COMANDOS.AQUILO<<"[ARTIGO]"<<COMANDOS.DUVIDA<<"\n"; // imprime : "palavra” [->][SUBS] ?
   cout <<" Y(y) / N(n) \n";
   cin >> YN;
   if(( YN == 'Y')||(YN == 'y'))
   {
	cout <<palavra<<COMANDOS.AQUILO<<"[CLASS]"<<COMANDOS.SIG<<COMANDOS.DUVIDA<<"\n"; // "palavra” [->][CLASS][SIG]?
    A_DEF();
    A_IND();
   }
   	if(( YN == 'N')||( YN == 'n'))
	{
	 	cout <<SYSTEMA<<COMANDOS.DUVIDA<<"\n";
		cout << COMANDOS.OK;
	}
  } 
}

void A_DEF()
{
 string aux1_artigo; // Variavel auxiliar ARTIGO + DEFINIDO
 string COMANDO_ARTIGO; // Variavel para juntar os comnados
 string DEF="{DEFINIDO}";
 string aux_nosig;
 aux_nosig=COMANDOS.NAO+COMANDOS.SIG; // Concatena as strings ficando NAO+SIG = "[NO]{SIG}"
if (PL == 1) 
 {
     cout <<"\n"<<letra<<" = "<<"[ARTIGO]"<<COMANDOS.ISTO<<DEF<<COMANDOS.DUVIDA<<endl;
     cin >> COMANDO_ARTIGO;
     
     aux1_artigo="[ARTIGO]"+DEF;
     if (COMANDO_ARTIGO == aux1_artigo) 
     {
        
           PesquisaATXT_DEF();                         //Pesquisa Arquivo TXT Artigo 
                                                      // se existe alguma letra igual
     }
     if (COMANDO_ARTIGO != aux1_artigo)
      {  
        if (COMANDO_ARTIGO == aux_nosig)
        {
            cout <<letra<<COMANDOS.AQUILO<<aux_nosig<<endl; 
             Entrada_dados();                        //Retorna a Entrada de dados.
        } 
         cout <<"COMANDO INVALIDO"<<endl;     
      }
 }
 if (PL == 2)
 {  
     cout <<"\n"<<palavra<<" = "<<"[ARTIGO]"<<COMANDOS.ISTO<<DEF<<COMANDOS.DUVIDA<<endl;
     cin >> COMANDO_ARTIGO;
     
     aux1_artigo="[ARTIGO]"+DEF;
     if (COMANDO_ARTIGO == aux1_artigo) 
     {
        
           PesquisaATXT_DEF();                         //Pesquisa Arquivo TXT Artigo 
                                                      // se existe alguma letra igual
     }
     if (COMANDO_ARTIGO != aux1_artigo)
      {  
        if (COMANDO_ARTIGO == aux_nosig)
        {
             cout <<palavra<<COMANDOS.AQUILO<<aux_nosig<<endl;
             Entrada_dados();                        //Retorna a Entrada de dados.
        } 
         cout <<"COMANDO INVALIDO"<<endl;     
      }
 }    
}

void A_IND()
{
 string aux2_artigo; // Variavel auxiliar ARTIGO + INDEFINIDO
 string COMANDO_ARTIGO; // Variavel para juntar os comnados
  string INDEF="{INDEFINIDO}";
  string aux_nosig;
  aux_nosig=COMANDOS.NAO+COMANDOS.SIG; // Concatena as strings ficando NAO+SIG = "[NO]{SIG}"
 if (PL == 1) 
 {
     cout <<letra<<" = "<<"[ARTIGO]"<<COMANDOS.ISTO<<INDEF<<COMANDOS.DUVIDA<<endl;
     cin >> COMANDO_ARTIGO;
     
     aux2_artigo="[ARTIGO]"+INDEF;
     if (COMANDO_ARTIGO == aux2_artigo)
     {
       
            PesquisaATXT_INDEF();                      //Pesquisa Arquivo TXT Artigo 
                                                     // se existe alguma letra igual
     }
     if (COMANDO_ARTIGO != aux2_artigo)
     {    
         if (COMANDO_ARTIGO == aux_nosig)
        {
             cout <<palavra<<COMANDOS.AQUILO<<aux_nosig<<endl;
             Entrada_dados();                        //Retorna a Entrada de dados.
        } 
         cout <<"COMANDO INVALIDO"<<endl;     
     }
 }
 if (PL == 2)
 {  
     cout <<palavra<<" = "<<"[ARTIGO]"<<COMANDOS.ISTO<<INDEF<<COMANDOS.DUVIDA<<endl;
     cin >> COMANDO_ARTIGO;
     
     aux2_artigo="[ARTIGO]"+INDEF;
     if (COMANDO_ARTIGO == aux2_artigo)
     {
        
            PesquisaATXT_INDEF();                      //Pesquisa Arquivo TXT Artigo 
                                                      // se existe alguma letra igual
     }
     if (COMANDO_ARTIGO != aux2_artigo)
     {    
        if (COMANDO_ARTIGO == aux_nosig)
        {
             cout <<palavra<<COMANDOS.AQUILO<<aux_nosig<<endl;
             Entrada_dados();                        //Retorna a Entrada de dados.
        } 
         cout <<"COMANDO INVALIDO"<<endl;      
     }
 }    
}

void Subs()
{
     char YN;
     string SUBS_CLASS=" ";
     int CLASS_SUBS=0;
     string COMANDO_SUBS;
     struct COMANDOS_S{
     string S_F_P, S_F_D, S_F_S, S_F_C;
     string S_S_CON, S_S_A, S_S_P, S_S_COL; 
     string S_GE_B, S_GE_H, S_GE_U, S_GE_U_E, S_GE_U_C2G,S_GE_U_S;
     string S_N_S, S_N_C;
     string S_GR_A, S_GR_S;
     }COMANDOS_S;
     COMANDOS_S.S_F_P="{PRIMITIVO}", COMANDOS_S.S_F_D="{DERIVADO}", COMANDOS_S.S_F_S="{SIMPLES}", COMANDOS_S.S_F_C="{COMPOSTO}";
     COMANDOS_S.S_S_CON="{CONCRETO}", COMANDOS_S.S_S_A="{ABSTRATO}", COMANDOS_S.S_S_P="{PROPRIO}", COMANDOS_S.S_S_COL="{COLETIVO}"; 
     COMANDOS_S.S_GE_B="{BIFORMES}", COMANDOS_S.S_GE_H="{HETERO}", COMANDOS_S.S_GE_U="{UNIFOR}", COMANDOS_S.S_GE_U_E="{EPICENOS}",COMANDOS_S.S_GE_U_C2G="{COMUNS2G}",COMANDOS_S.S_GE_U_S="{SOBRECOMUNS}";
     COMANDOS_S.S_N_S="{SIMPLES}", COMANDOS_S.S_N_C="{COMPOSTO}";
     COMANDOS_S.S_GR_A="{ANALITICO}", COMANDOS_S.S_GR_S="{SINTETICO}";
     string aux_nosig;
     aux_nosig=COMANDOS.NAO+COMANDOS.SIG;
	 string AUX_SUBS1="[SUBS]";
	cout <<"\n"<<palavra<<COMANDOS.AQUILO<<AUX_SUBS1<<COMANDOS.DUVIDA<<"\n"; // imprime : "palavra” [->][SUBS] ?
	cout <<" Y(y) / N(n) \n";
	cin >> YN;
	if(( YN == 'Y')||(YN == 'y'))
	{
		cout <<palavra<<COMANDOS.AQUILO<<"[CLASS]"<<COMANDOS.SIG<<COMANDOS.DUVIDA<<"\n"; // "palavra” [->][CLASS][SIG]?
		cin >> COMANDO_SUBS;
		if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_F_P)                                              //AUX_S_F_P
		{
			S_F_P();
		}
		if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_F_D)                                              //AUX_S_F_D
		{
			S_F_D();
		}
		if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_F_S)                                              //AUX_S_F_S
		{
			S_F_S();
		}
		if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_F_C)//AUX_S_F_C
		{
			S_F_C();
		}
		if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_S_CON)//AUX_S_S_CON
		{
			S_S_CON();
		}
		if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_S_A)//AUX_S_S_A
		{
			S_S_A();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_S_P)//AUX_S_S_P
		{
			S_S_P();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_S_COL)//AUX_S_S_COL
		{
			S_S_COL();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_GE_B)//AUX_S_GE_B
		{
			S_GE_B();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_GE_H)//AUX_S_GE_H
		{
			S_GE_H();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_GE_U)//AUX_S_GE_U
		{
			S_GE_U();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_GE_U_E)//AUX_S_GE_U_E
		{
			S_GE_U_E();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_GE_U_C2G)//AUX_S_GE_U_C
		{
			S_GE_U_C2G();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_GE_U_S)//AUX_S_GE_U_S
		{
			S_GE_U_S();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_N_S)//AUX_S_N_S
		{
			S_N_S();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_N_C)//AUX_S_N_C
		{
			S_N_C();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_GR_A)//AUX_S_GR_A
		{
			S_GR_A();
		}
		 if(COMANDO_SUBS == AUX_SUBS1+COMANDOS_S.S_GR_S)//AUX_S_GR_S
		{
			S_GR_S();
		}
	}
	if(( YN == 'N')||( YN == 'n'))
	{
	 	cout <<SYSTEMA<<COMANDOS.DUVIDA<<"\n";
		cin >> COMANDO_SUBS;
		cout << COMANDOS.OK;
	}
}
	// Formação
	void S_F_P() 	// Primitivo
	{
		cout << "O Susbstantivo eh Primitivo"<<endl;
	}
	void S_F_D()	// Derivado
	{
		cout << "O Susbstantivo eh Derivado"<<endl;
	}
	void S_F_S()	// Simples
	{
		cout << "O Susbstantivo eh Simples"<<endl;
	}
	void S_F_C()	// Composto
	{
		cout << "O Susbstantivo eh  Composto"<<endl;
	}

	// Semantica
	void S_S_CON()	// Concreto
	{
		cout << "O Susbstantivo eh Concreto"<<endl;
	}
	void S_S_A()		//Abstrato
	{
		cout << "O Susbstantivo eh Abstrato"<<endl;
	}
	void S_S_P()		// Próprio
	{
		cout << "O Susbstantivo eh Próprio"<<endl;
	}
	void S_S_COL()	// Coletivo
	{
		cout << "O Susbstantivo eh Coletivo"<<endl;
	}

	// Gênero
	void S_GE_B()		// Biforme
	{
		cout << "O Susbstantivo eh Biforme"<<endl;
	}
	void S_GE_H()		// Heterôgenio
	{
		cout << "O Susbstantivo eh Heterôgenio"<<endl;
	}
	void S_GE_U()		// Uniforme
	{
		cout << "O Susbstantivo eh Uniforme"<<endl;
	}
	void S_GE_U_E()	// U. Epicenos
	{
		cout << "O Susbstantivo eh U. Epicenos"<<endl;
	}
	void S_GE_U_C2G()	// U. Comuns de 2 gêneros
	{
		cout << "O Susbstantivo eh U. Comuns de 2 gêneros"<<endl;
	}
	void S_GE_U_S()	// U. Sobrecomuns
	{
		cout << "O Susbstantivo eh U. Sobrecomuns"<<endl;
	}

	// Numero
	void  S_N_S()		// Simples
	{
		cout << "O Susbstantivo eh Simples"<<endl;
	}
	void  S_N_C()		// Composto
	{
		cout << "O Susbstantivo eh Composto"<<endl;
	}

	// Grau
	void S_GR_A()		// Analitico
	{
		cout << "O Susbstantivo eh Analitico"<<endl;
	}
	void S_GR_S()		// Sintético
	{
		cout << "O Susbstantivo eh Sintético"<<endl;
	}

void PesquisaATXT_DEF()                                // Verifica se já existe a letra
{
   char MEMO[]="[MEMO]";
   char aux_atxt_def[2];
     ifstream in3("Artigo_def.pci");                   // Abre arquivo para leitura
     while(in3>>aux_atxt_def)
     {         
          cout<<MEMO<<COMANDOS.IGUAL<<" "<<aux_atxt_def<<"\n ";
          if(strcmp(aux_atxt_def,letra)==0)                    //Verifica se ja existe a palavra no arquivo.
          {
               cout<<"Artigo"<<COMANDOS.IGUAL<<letra<<endl;     //Caso estiver imprime
               Entrada_dados();                        //Retorna a Entrada de dados.
          }
     }
     in3.close();                                      //fecha arquivo in
     Gravando_arquivo_Artigo_DEF();                    //Grava a palavra informada no arquivo Palavras.txt   
}         

void Gravando_arquivo_Artigo_DEF()                     //Grava palavra informada
{
     ofstream arquivodef("Artigo_def.pci",ios::out|ios::app); //Abre arquivo para gravacao
     arquivodef<<letra<<" "<<endl;
     arquivodef.close();                               //Fecha arquivo
     Entrada_dados();                                  //Retorna a Entrada de dados        
}
void PesquisaATXT_INDEF()
{
   char MEMO[]="[MEMO]";
   char aux_atxt_indef[2];
     ifstream in4("Artigo_indef.pci");                 // Abre arquivo para leitura
     while(in4>>aux_atxt_indef)
     {         
          cout<<MEMO<<COMANDOS.IGUAL<<" "<<aux_atxt_indef<<"\n ";
          if(strcmp(aux_atxt_indef,palavra)==0)                   //Verifica se ja existe a palavra no arquivo.
          {
               cout<<"Artigo"<<COMANDOS.IGUAL<<palavra<<endl;    //Caso estiver imprime
               Entrada_dados();                       //Retorna a Entrada de dados.
          }
     }
     in4.close();                                     //fecha arquivo in
     Gravando_arquivo_Artigo_INDEF();                 //Grava a palavra informada no arquivo Palavras.txt   
}         

void Gravando_arquivo_Artigo_INDEF()                  //Grava palavra informada
{
     ofstream arquivoindef("Artigo_indef.pci",ios::out|ios::app); //Abre arquivo para gravacao
     arquivoindef<<palavra<<" "<<endl;
     arquivoindef.close();                            //Fecha arquivo
     Entrada_dados();                                 //Retorna a Entrada de dados        
}
                
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
