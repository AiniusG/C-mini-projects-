//Dokumentacija
//Autorius: Ainius Gecas
//Failo paskirtis: failu zodziu esancius skaicius pakeisti i ju pirmas raides.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 255
#define BUFFER 128
//Funkcija suranda source file, jeigu jis neduodas arba pateiktas neteisingai.
FILE* find_source(char* source_name, FILE* source){

    //Failas atidaromas su append, kad jo gale butu galima prideti space, padeda susitvarkyti su paskutiniu teksto zodziu
    source = fopen(source_name, "a");
    while(source == NULL){
        fclose(source);
        source_name = malloc(BUFFER*sizeof(char));
        printf("File not found... Please enter a valid file: ");
        scanf("%s", source_name);
        source = fopen(source_name, "a");   //append
    }
    fprintf(source," ");
    fclose(source);
    source = fopen(source_name, "r");
    free(source_name);
    return source;
}
//Funckija transformuoja sakiny pagal uzdavinio reikalavimus
void transform_sentence(char *sentence, FILE* destination){
    char *gap;
    gap = malloc(BUFFER * sizeof(char));
    char first_letter = '\0';
    int length = strlen(sentence), words = 1;

    //Skaiciuojami ir paskirstomi zodziai tarp masyvu ribu (aka iesko pirmo tarpo tarp zodziu)
    for(int i = 0; i < length; ++i){
        if(sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t'){
            gap[words] = i;
            words++;
        }
    }

    gap[0] = 0; //Pirmo zodzio pradzia bus arba eilutes pradzia (gap[0] = 0) arba po tarpo, kuri suras funkcija
    int counter = 1;

    //Tol kol eiluteje yra zodziu
    while(words != 0){
        char first_letter;
        int only_numbers = 0;

        //Pradedama nuo tarpo pries zodi, tesiama iki kito tarpo
        for(int i = gap[counter-1]; i < gap[counter]; ++i){
            if((sentence[i] >= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122)){
                first_letter = sentence[i];
                only_numbers = 1;
                break;
            }
        }
        //Jeigu skaiciuje nera vien skaiciai (aka only_numbers = 1) tada vykstoma transformacija
        if(only_numbers){

            for(int i = gap[counter-1]; i < gap[counter]; ++i){
                if(sentence[i] >= 48 && sentence[i] <= 57){
                    sentence[i] = first_letter;
                }
            }
        }

        words--;
        counter++;
    }
    fprintf(destination, sentence);
    free(gap);
}
//Funkcija priskriai sakini, kuris veliau transformuojamas, tol, kol yra teksto
void transformation(char* sentence, FILE* source, FILE* destination){

    while((fgets(sentence, LINE_LENGTH, source) != NULL)){
        int sentence_length = strlen(sentence);
        transform_sentence(sentence, destination);
        sentence = malloc(BUFFER* sizeof(char));
    }
}
int main(int argc, char *argv[] )
{
    FILE *source, *destination;                         //source - is kur imamas info;destination - kur jis bus rasomas
    char *source_name, *destination_name, *sentence;

    //Jeigu duotas duomenu failas ir rezultatu failas
    if(argc == 3){
        source_name = argv[1];
        destination_name = argv[2];
        //Atidarom tarp w pirma, kad pravalyti visa praeita info, eilute gali buti istrinta jeigu to reikalautu vartotojas.
        destination = fopen(destination_name, "w");
        fclose(destination);
        destination = fopen(destination_name, "a");
        source = find_source(source_name, source);
    }

    //Jeigu duotas tik duomenu failas
    else if(argc == 2){
        source_name = argv[1];
        destination = stdout;
        source = find_source(source_name, source);
    }
    //Kitais atvejais
    else
    {
        source_name = malloc(BUFFER*sizeof(char));
        printf("Please enter the name of the source file: ");
        scanf("%s", source_name);
        destination = stdout;
        source = find_source(source_name, source);
    }
    //Pradedama transformacija
    sentence = malloc(BUFFER* sizeof(char));
    transformation(sentence, source, destination);

    fclose(source);
    fclose(destination);
    free(sentence);
    return 0;
}
