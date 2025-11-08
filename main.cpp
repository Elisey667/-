#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);
    int input_number;
    int Number = dist(gen);
    int lang;
    int attempts = 0;
    cout<<"Choose a language:"<<endl;
    cout<<"1. Russian"<<endl;
    cout<<"2. English"<<endl;
    cin>>lang;
    if (lang == 1){
        while (true) {
            cout<<"Введите число:";
            cin>>input_number;
            if (input_number > Number) {
                cout<<"Слишком много!"<<endl;
                attempts++;
            }
            else if (input_number < Number) {
                cout<<"Слишком мало!"<<endl;
                attempts++;
            }
            else if (input_number == Number) {
                attempts++;
                cout<<"Ты угадал!"<<endl;
                cout<<"Ваши попытки:" << attempts<<endl;
                break;
            }
        }
    }
    else if(lang == 2){
        while (true) {
            cout<<"Enter a number:";
            cin>>input_number;
            if (input_number > Number) {
                cout<<"Too much!"<<endl;
                attempts++;
            }
            else if (input_number < Number) {
                cout<<"Too little!"<<endl;
                attempts++;
            }
            else if (input_number == Number) {
                attempts++;
                cout<<"you guessed it!"<<endl;
                cout<<"Your attempts:"<<attempts<<endl;
                break;
            }
        }
    }
    return 0;
}
