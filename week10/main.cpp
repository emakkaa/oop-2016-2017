#include <iostream>
#define MAX_CHAR 50
#define DEFAULT_ARMY 5
using std::cout;
using std::endl;

class Hero {
private:
    
    char name[MAX_CHAR];
    int health;
    
public:
    
    
    Hero(){};
    
    Hero(const char _name[], int _health) : health(_health) {
        strcpy(name, _name);
    }
    
    int getHealth() const{
        return this->health;
    }
    
    void setHealth(int _newHealth) {
        if(_newHealth > 0){
            this->health = _newHealth;
        }
        else{
            this->health = 0;
        }
    }
    
    virtual void greet() = 0;
    
    virtual void attack(Hero* enemy) = 0;
    virtual ~Hero() { cout<<"deleted"<<endl;}
};

class Magician : public Hero {
    int mana;
    
public:
    
    
    Magician():Hero(){};
    
    Magician(const char _name[], int _health = 100, int _mana = 200)
    : Hero(_name, _health), mana(_mana) { }
    
    int getMana() const {
        return this->mana;
    }
    
    void attack(Hero* enemy) {
        enemy->setHealth(enemy->getHealth() - mana);
        this->mana -= 20;
    }
    
    void greet() {
        
        cout << "mana: " << mana << "\n";
    }
    
    ~Magician(){
        cout<<"Magician removed"<<endl;
    }
    
    void setMana(int _mana){
        if(_mana > 0){
            this->mana = _mana;
        }
        else{
            this->mana = 0;
        }
        
    }
};

class Warrior : public Hero {
    int rage;
    
public:
    
    Warrior(){};
    
    Warrior(const char _name[], int _health = 120, int _rage = 0)
    : Hero(_name, _health), rage(_rage) { }
    
    int getRage() {
        return rage;
    }
    
    void setRage(int _rage){
        if(_rage > 0){
            this->rage = _rage;
        }
        else{
            this->rage = 0;
        }
    }
    
    void greet() {
        
        cout << "rage: " << rage << endl;
    }
    
    void attack(Hero* enemy) {
        enemy->setHealth(enemy->getHealth() - (rage + 10));
        rage += 20;
    }

    ~Warrior(){
        cout<<"warrior removed"<<endl;
    }
};

//container
void generateArmy(Hero** &army, int size = 5){
    for(int index = 0; index < size; ++index){
        
        char symbol;
        std::cin>>symbol;
        switch (symbol) {
            case 'w':
                army[index] = new Warrior();
                break;
            case 'm':
                army[index] = new Magician();
                break;
            default:
                army[index] = new Magician();
        }
    }
}

//rofl
void makeArmyGreet(Hero** &army, int armySize = DEFAULT_ARMY ){
    for (int index = 0; index < armySize; ++index){
        army[index]->greet();
    }
}

int main() {
    
    Hero** heroes =new Hero*[DEFAULT_ARMY];
    generateArmy(heroes);
    makeArmyGreet(heroes);
    
    
    for(int i = 0; i < DEFAULT_ARMY; ++i){
        delete heroes[i];
    }
    
    delete [] heroes;
    
    return 0;
}
