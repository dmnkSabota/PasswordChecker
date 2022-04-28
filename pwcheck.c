#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

/*
Header:
    Password-check
    Dominik Sabota
    231274
*/

/*
 * Funkcia: level_1
 * ------------------
 * Zistuje ci sa v "hesle" (zadanom stringu) nachadza velke a male pismeno. 
 * 
 * upperCase: Hodnota True||False k overeniu ci sa v stringu nachadza velke pismeno  
 * lowerCase: Hodnota True||False k overeniu ci sa v stringu nachadza malee pismeno 
 * 
 * return: 1 ak level_1 splneny || 0 ak level_1 nesplneny
 */
int level_1(char *str){

    bool upperCase=false;
    bool lowerCase=false;

    for(int i=0; str[i] != '\n'; i++){
        if(str[i] >= 'a'&& str[i] <= 'z'){
            lowerCase = true;
        } 
        if(str[i] >= 'A'&& str[i] <= 'Z'){
            upperCase = true;
        }
    }

    if (lowerCase && upperCase){
        return 1;
    }

    return 0;
}

/*
 * Funkcia: level_2
 * ------------------
 * Zistuje ci sa v "hesle" (zadanom stringu) nachadza 
 * velke pismeno || male pismeno || cislo || specialny znak 
 * na z8klade prijatych parametrov. 
 * 
 * control: hodnota splnenych kategorii zadanych parametrom (groups)
 * 
 * return: 1 ak level_2 splneny (control >= groups) || 0 ak level_2 nesplneny (control >= groups) 
 */
int level_2(char* str, int groups ){
    
    if(groups > 4){ // osetrenie pripadu ze by bol zadany parameter vacsi ako je potrebne
        groups=4;
    }

    int control=0;

    for(int i=0; str[i] != '\n'; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            control++;
            break;
        } 
       
    } 

    for(int i=0; str[i] != '\n'; i++){
        if((str[i] >= ' ' && str[i] <= '/') ||
        (str[i] >= ':' && str[i] <= '@') ||
        (str[i] >= '[' && str[i] <= '`') || 
        (str[i] >= '{' && str[i] <= '~')){
            control++;
            break;
            
        } 
       
    } 
    
    for(int i=0; str[i] != '\n'; i++){
        if(str[i] >= 'A'&& str[i] <= 'Z'){
            control++;
            break;
        }
    }

    for(int i=0; str[i] != '\n'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            control++;
            break;
        } 
    }

    if(control >= groups){
        return 1;
        
    }
    return 0;
}

/*
 * Funkcia: level_3
 * ------------------
 * Zistuje ci sa v "hesle" (zadanom stringu) nachadza 
 * sekvencia rovnakych znakov, s dlzkou hodnoty zadaneho parametra (chars).
 * 
 * count: hodnota dlzky sekvencie rovnakych pismen 
 * 
 * return: 1 ak level_3 splneny (count <= chars) || 0 ak level_3 nesplneny (count >= chars) 
 */
int level_3(char* str, int chars){

    int count = 1;

    for(int i=1; str[i] != '\n'; i++){
        if(str[i] == str[i-1]){
            count++;
        }
        else{
            count=1;
        }
        if(count >= chars){
            return 0;
        }
    }

    return 1;    
}

/*
 * Funkcia: level_4
 * ------------------
 * Zistuje ci sa v "hesle" (zadanom stringu) nachadzaju 
 * dva rovnake podretazce, s dlzkou hodnoty zadaneho parametra (length).
 * 
 * counter: hodnota rovnakej postupnosti charakterov dvoch podretazcov 
 * position: pomocna hodnota na podrzanie si adresy pointeru 
 * 
 * return: 1 ak level_4 splneny (count != length) || 0 ak level_2 nesplneny (count == length) 
 */
int level_4(char* str, int length){

    int position, counter = 0;

    for(int x = 0; str[x] != '\n'; x++){

        if(str[x]==str[x+1]){
            x++;
        }

        position = x;

        for(int y = x+1; str[y] != '\n'; y++){
            if(str[position]==str[y]){
               position++;
               counter++;
               if(counter==length){
                   return 0;
               }
            }else{
                position = x;
                counter = 0;
            }
        }
        counter=0;
    }

    return 1;
}

/*
 * Funkcia: str_len
 * ------------------
 * Spocita dlzku stringu.
 * 
 * counter: hodnota dlzky stringu 
 * 
 * return: hodnotu premennej counter
 */
int str_len(char *str){
    int counter=0;
    for(int i=0; str[i]!='\0';i++){
        counter++;
        
    }
    return counter;
}

/*
 * Funkcia: in_arr
 * ------------------
 * Skontroluje ci je charakter v poly.
 * 
 * c: zadany character
 * 
 * return: 1 ak sa c nachadza v poly || 0 ak sa c nenachadza v poli
 */
int in_arr(char c, char *str){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == c){
            return 1;
        }
    }
    return 0;
}

/*
 * Funkcia: str_compare
 * ------------------
 * Porovna dva stringy.
 * 
 * return: 1 ak sa stringy rovnaju || 0 ak sa stringy nerovnaju
 */
int str_compare(char *str1, char *str2){
    if(str1 == NULL && str2==NULL){ // ak stringy neobsahuju nic, automaticky sa rovnaju
        return 1;
    }

    if(str_len(str1) != str_len(str2)){
        return 0;
    }

    for(int i =0; str1[i] != '\0'; i++){
        if(str1[i] != str2[i]){
            return 0;
        }
    }
    return 1;
}

/*
 * Funkcia: nchars
 * ------------------
 * Spocita kolko roznych/unikatnych znakov sa nachadza vo vsetkych zadanych "heslach".
 * 
 * unique_index: hodnota poctu roznych znakov 
 * 
 * return: hodnotu premennej unique_index
 */
int nchars(char *znaky, int unique_index, char *unique){
    
    for(int i = 0; znaky[i] != '\n'; i++){
      if(in_arr(znaky[i],unique) != 1 ){
          unique[unique_index] = znaky[i];
          unique_index++;
      }
    }
    return unique_index;

}

/*
 * Funkcia: min
 * ------------------
 * Vyhodnoti dlzku najkratsieho stringu.
 * 
 * c: hodnota dlzky stringu 
 * 
 * return: c || min_chars (dlzka doteraz najkratsieho stringu)
 */
int min(char *pws, int min_chars){
    int c=0;
    for(int i =0; pws[i] != '\0'; i++){
        c++;
    }
    if(c <min_chars){ //ak je dlzka stringu mensia ako dlzka predoslych stringov, prepise sa  
        return c;
    }
    return min_chars;
}

/*
 * Funkcia: avg
 * ------------------
 * Spocita pocet vsetkych znakov na neskorsie spocitanie priemernej dlzky stringu.
 * 
 * pocet_znakov: hodnota vsetkych znakov vsetkych stringov dokopy
 * 
 * return: pocet_znakov
 */
int avg(char *pws){
    int pocet_znakov = 0;
    for(int i= 0; pws[i] !='\n'; i++){
        pocet_znakov++;
    }
    return pocet_znakov;
}

/*
 * Funkcia: stats_check
 * ------------------
 * Kontroluje ci vobec bol zadany argument (--stats) na vypisanie statistik && kontroluje ci bol spravene zadany.
 * 
 * return: 1 ak vstupny argument bol zadany a bol spravne zadany || 0 ak vstupny argument nebol zadany || ak vstupny argument bol zadany ale nie spravne  
 */
int stats_check(char *p){
    if(p != NULL){
        if(str_compare(p,"--stats") == 1){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}

int main(int argc, char *argv[]){
    
    char pws[101]={0};
    char unique[128]; // pole roznych znakou velkosti ASCII tabulky
    int unique_index = 0;
    int min_chars = 101;
    double avg_chars = 0; //pocet vsetkych znakov vsetkch hesiel
    int pws_count = 0; //pocet hesiel
    char *garbage_collector; //na nadvysny string z funkcie strtol

    if (argc < 3 || argc > 4){
        fprintf(stderr, "Error: Zadany nespravny pocet argumentov!\n");
        return 1;
    }
    
    long int lvl = strtol(argv[1],&garbage_collector, 10); // premiena string na int a vyhodi nadvysne charaktery

    if(*garbage_collector != '\0'){
        fprintf(stderr, "Error: Arguement is not valid!\n");
        return 1;
    }

    long int prm = strtol(argv[2],&garbage_collector, 10);

    if(*garbage_collector != '\0'){
        fprintf(stderr, "Error: Arguement is not valid!\n");
        return 1;
    }
    

    if(lvl < 1 || lvl > 4 ){
        fprintf(stderr, "Error: First arguement is not valid!\n");
        return 1;
    }
    
    if(prm >= LONG_MAX){
            prm = INT_MAX;
        }

    if(prm < 1){
        fprintf(stderr, "Error: Second arguement is not valid!\n");
        return 1;
    }

    if (argc == 4 && stats_check(argv[3]) == 0){
        fprintf(stderr, "Error: Third argument invalid!(expected --stats)");
        return 1;
    }

    while(1){
        
        if (fgets(pws,103,stdin) == NULL) // osetrenie pripadu ze by input nic neobsahoval
            break;
        
        if(str_len(pws) >= 102){
            fprintf(stderr, "Error: Password is too long!\n");
            return 1;
        }


        int level_check=0;
        if(lvl >= 1){
            level_check = level_1(pws);
        }
        if(lvl >= 2 && level_check == 1){
            level_check = level_2(pws,prm);
        }
        if(lvl >= 3 && level_check == 1){
            level_check = level_3(pws,prm);
        }
        if(lvl >= 4 && level_check == 1){
            level_check = level_4(pws,prm);
        }
        if(level_check == 1){
            fprintf(stdout,"%s", pws);
        }
        if(stats_check(argv[3]) == 1){
            unique_index = nchars(pws,unique_index,unique);
            min_chars = min(pws, min_chars);
            avg_chars += avg(pws);
            pws_count++;
        }
    }

    if(stats_check(argv[3]) == 1){
        fprintf(stdout, "Statistika:\n");
        fprintf(stdout, "Ruznych znaku: %d\n", unique_index);
        fprintf(stdout, "Minimalni delka: %d\n", min_chars-1);
        fprintf(stdout, "Prumerna delka: %.1f\n", avg_chars/pws_count);
    }
    return 0;
}