#include <stdio.h>

char zvetsi(char adresa[]);     //deklaruji, protoze volam zvetsi pred definici

char nacti(char pole[]){        //nacitani seznamu adres ze stdin do pole
    int c = 0;
    int i = 0;
    int j = 1;
    while((c = fgetc(stdin)) != EOF){
        pole[i] = c;
        if(pole[i]=='\n'){
            j = 0;
        }
        i++;
        j++;
        if((j%101)==0){
            while((c = fgetc(stdin)) != '\n'){
            }
            pole[i] = c;
            if(pole[i]=='\n'){
                j = 0;
            }
            i++;
            }
        }

    zvetsi(pole);
    pole[i]='\0';
    return 0;
}

int prazdna_adresa(int argc, char pole[]){  //vypis vsech pocatecnich znaku
    if(argc == 1){
        int vzdalenost = 'z' - 'a';
        char poc_zn[vzdalenost];       //poc_zn = pocatecni znaky
        int i = 0;                     
        int poradi;                   
        for(i = 0; i<= vzdalenost; i++){
            poc_zn[i] = ' '; 
        }
        i = 0;
        while(pole[i]!='\0'){
            if(i==0){
                if((pole[i]>='a')&&(pole[i]<='z')){
                    poradi = pole[i]-'a';
                }
                else if((pole[i]>='A')&&(pole[i]<='Z')){
                   poradi = pole[i]-'A'; 
                }
                poc_zn[poradi]=pole[i];
            }
            if((pole[i]=='\n')&&(pole[i+1]!='\0')){
                if((pole[i+1]>='a')&&(pole[i+1]<='z')){
                    poradi = pole[i+1]-'a';
                }
                else if((pole[i+1]>='A')&&(pole[i+1]<='Z')){
                    poradi = pole[i+1]-'A';
                }
                
                poc_zn[poradi]=pole[i+1];
            }
            i++;
        }
        poc_zn[vzdalenost+1]='\0';

        for(i = 0; i <= vzdalenost; i++){    
            if((poc_zn[i]>='a')&&(poc_zn[i]<='z')){       
                poc_zn[i]-='a'-'A';
            }
        }

        i = 0;
        printf("\nEnable: ");
        while(poc_zn[i]!='\0'){
            if(poc_zn[i]!=' '){
               printf("%c", poc_zn[i]);
            }
            i++; 
        }
        printf("\n\n");
    }
    return 0;
}

int hledam(char pole[], char adresa[], int delka, char skupina[]){      // hledani vyskytu adresy
    int i = 0;                                                          // v poli adres
    int j = 0;
    int k = 0;
    int porovnavac = 0;
    int vyskyt = 0;
    char enable[26];
    int poradi;

    while(i < 26){
        enable[i] = 0;
        i++;
    }
    i = 0;
    while(pole[i]!='\0'){
        if((i==0)||(pole[i]=='\n')||(j>0)){
            if(pole[i]=='\n'){
                i++;
            }
            if(adresa[j] == pole[i]){
                porovnavac++;
                j++;
            }
            else{
                porovnavac = 0;
                j = 0;
            }
        }
        if(porovnavac == delka){
            vyskyt ++;
            int spust_enable = 0;
                while(pole[i+1]!='\n'){
                    if(spust_enable == 0){
                    poradi = pole[i+1]-'A';
                    spust_enable = 1;
                        if((enable[poradi]<='A')||(enable[poradi]>='Z')){
                            enable[poradi] = pole[i+1];
                        }
                    }
                    adresa[j]=pole[i+1];
                    i++;
                    j++;
                }
                adresa[j] = ' ';
                adresa[j+1]=' ';
                int vk = 0;         //vk = vnitrni k
                
                while(vk <= j){
                    skupina[k]=adresa[vk];
                    k++;
                    vk++;
                }
                j = 0;
                porovnavac = 0;
            }
        i++;
    }
    if(vyskyt == 1){
        printf("\nFOUND: %s\n\n", adresa);
        return 0;
    }

    i = 0;
    if(vyskyt>1){
        printf("\nEnable:");
        while(i < 26){
        if((enable[i]>='A')&&(enable[i]<='Z')){
            printf("%c", enable[i]);
        }
        i++;
        }
        printf("\n\n");
        return 0;
    }

    if(porovnavac==0){
        printf("\nNot found\n\n");
    }
    return 0;
}

int ds(char *slovo){            //ds = delka slova, nahrada strlen
    int d = 0;
    while(slovo[d]!='\0'){
        d++;
    }
    return d;
}

char zvetsi(char adresa[]){     //prevod vstupni adresy na velka pismena
    int i = 0;
    while(adresa[i]!='\0'){
        if((adresa[i]>='a')&&(adresa[i]<='z')){       
            adresa[i]-='a'-'A';
        }
        i++;
    }
    return 0;
}

int main(int argc, char *argv[]){
    
    char *slovo = argv[1];
    int d = 1;
    char adresa[100];   //adresa z parametru argv[1]
    char pole[4243];
    char skupina[100];
    int i = 0;
    int j = 0;
    int delka = 0;
    while(i<100){
        adresa[i] = 0;
        skupina[i] = 0;
        i++;
    }
    i = 0;
    while(i<4243){
        pole[i] = ' ';
        i++;
    }

    while(d<argc){      //osetreni viceslovoveho vstupu
        i = 0;
        slovo = argv[d];
        while(i<ds(slovo)){
            adresa[j]=slovo[i];
            i++;
            j++;
            delka++;
        }
        adresa[j]=' ';
        d++;
        j++;
        delka++;
    }
    delka--;
    adresa[j]='\0';

    zvetsi(adresa);
    nacti(pole);                   

    if(argc == 1){
        prazdna_adresa(argc, pole);
        return 0;
        }

    hledam(pole, adresa, delka, skupina);

    return 0;
}