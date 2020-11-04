#include<iostream>
#include<fstream>

using namespace std;

class block{
    private:
        string word;
        string meaning;

    public:
        block(){
            word = "word";
            meaning = "meaning";
        }

        int enter_data(){
            cout<<"Enter the new word : ";
            getline(cin,word);
            cout<<"\nEnter the meaning of the word : ";
            getline(cin,meaning);
            return 0;
        }

        int read_data(){
            cout<<"WORD :- "<<word<<endl;
            cout<<"MEANING :- "<<meaning<<endl;
            return 0;
        }

        int input_to_file(){
            fstream fio;
            fio.open("Dictonary.DAT",ios::app | ios::binary);


            block bwrite;
            bwrite.enter_data();

            fio.write((char*)&bwrite, sizeof(bwrite));
            return 0;
        }

        int read_from_file(){
            fstream fio;
            fio.open("Dictonary.DAT",ios::in|ios::binary);

            block bread;
            while(!fio.eof()){
                fio.read((char*)&bread, sizeof(bread));
                bread.read_data();
                cout<<"1";
            }
            return 0;
            
        }



};



int main(){
   
    block b1;
    b1.input_to_file();
    b1.input_to_file();
    b1.read_from_file();
    return 0;
}