#include <iostream>
#include <string>

using namespace std;


/*
    Exercise Title: Understanding Custom Constructors with Inheritance
*/


/*
    Tasks:

    1. In the below code describe the purpose of the GameObject class. 
    What common functionality does it provide for its derived classes?
    Answer: Game Object sinifinin meqsedi nedir? Game object oyunda olan Player , Enemy , Adventure child klasslarina 2 xususiyyeti oturur.Bunlardan birir diplayinfo() ,
    digeri ise namedir.Bu oyunda child classlarda tez tez istifade olunduguna gore tekrarciligin qarsisin almaq ucucn bir defe parent class da yaradilib ve sonra child 
    klasslara inheritance vasitesi ile bu xususiyyetler oturulur.

    2. Explain the concept of inheritance as demonstrated in the code. 
    How are the Player, Enemy, and Character classes related to the GameObject class?
    Answer: Inheritance novu publicdir bu o demekdir ki public inheritance parent klassda olan public ve protected olunmus methodlar ve digerleri 
    child klasslar ucun elcatandir.(Yeni name xususiyyetine ve displayInfo() , methoduna saib olurlar.)Hemcinin onlarin oz private xususiyyetleri de var ki bu xususiyyetler
    ozlerinden basqa hec kime aid deyil.Player → health, Enemy → damage, Character → level -->Bunlardir.

    3. Identify and describe the purpose of the constructors in the derived classes (Player, Enemy, Character). 
    How do they initialize the member variables of the derived classes and the base class?
    Answer: Player , Enemy , Character child klassinda olan konstruktorlar base classdaki konstruktoru cagirir.Ve oz private elementlerin menimsedirler.
    Bunun sebebi odur ki parent classda olan name private uzvdur ve o bir basa child klass terefinden cagirila bilmez.

    4. In the main function, three objects are created: player, enemy, and character. 
    Explain how these objects are constructed using the provided constructors.
    Answer:Player player("Hero", 100);
    Enemy enemy("Goblin", 20);
    Character character("Adventurer", 5); --> main de bu 3 obyekt yaradilib bunlar birinci child klasslara istinad edirler daha sonra child klasslar
    parent klasslarda olan name ve display e istinad edir ve neticede o obyektlere menimsedilmis informasiya terminala cixir.

    5. Describe the benefits of using inheritance in this scenario. 
    How does it contribute to code organization and reusability?
    Answer: En esas faydasi kod tekrarinin qarsisin almaqdir. Hemcinin classlar daha oxunaqli ve anlasilan olur.Hem de genislenme asandir meselen indi bura 
    yeni child klass elave ede bilerem onu parent klassdan nesillendirib parent klassin xususiyyetlerinden ve methodlarindan istifade ede bilerem. 

    6. Imagine you need to add a new class called Weapon that inherits from GameObject and has an additional attribute called damage. 
    Extend the code to include the Weapon class and demonstrate its usage in the main function.
    Answer: Cavab asagidadir.

    7. Modify the Character class to include an additional attribute, 
    such as experience, and update its constructor and displayInfoCharacter method accordingly. 
    Reflect on how these changes affect the overall structure of the program.
    Answer: Cavab asagidadir.

    8. Discuss potential improvements or alternative approaches that 
    could be taken to design a similar system with better maintainability and extensibility.
    Tekmillesdirme biz ede bilerik meselen polimorfizmden istifade ede bilerik displaya virtual elave edib tekrar her xarakter ucun meselen displayCharacter , 
    displayEnemy ve s yaratmaga ehtiyac qalmazdi.Bir de menisedilen eded yoxlansa daha yaxsi olar cunki bu kodda menfi olanda her hansi integer deyisen o xeta vermir.
    Bir de yeni methodlar ve attributlar elave etmek olar.

*/



class GameObject {
    public:
        GameObject(const string& name) : name(name) {
            // Common initialization for all game objects
        }

        void displayInfo() {
            cout << "Name: " << name << "\n";
        }

    private:
        string name;
};


class Player : public GameObject {
    public:
        Player(const string& name, int health) : GameObject(name), health(health) {
            // Specific initialization for players
        }

        void displayInfoPlayer() {
            displayInfo();
            cout << "Health: " << health << "\n";
        }

    private:
        int health;
};


class Enemy : public GameObject {
    public:
        Enemy(const std::string& name, int damage) : GameObject(name), damage(damage) {
            // Specific initialization for enemies
        }

        void displayInfoEnemy() {
            displayInfo();
            cout << "Damage: " << damage << "\n";
        }

    private:
        int damage;
};


class Character : public GameObject {
    public:
        Character(const std::string& name, int level , string experience) : GameObject(name), level(level) , experience(experience) {
            // Specific initialization for characters
        }

        void displayInfoCharacter() {
            displayInfo();
            cout << "Level: " << level << "\n";
            cout << "Experience: " << experience <<endl;
        }

    private:
        int level;
        string experience;
};
class Weapon : public GameObject{
    private: 
    int damage;
    public:
    Weapon(const std::string& name, int damage) : GameObject(name), damage(damage) {
    }
    void displayInfoWeapon(){
        displayInfo();
        cout << "Damage: " << damage << "\n";
    }
};
int main() {

    system("cls");

    /*   Example Usage   */
    Player player("Hero", 100);
    Enemy enemy("Goblin", 20);
    Character character("Adventurer", 5 , "Middle");

    player.displayInfoPlayer();
    cout << endl;

    enemy.displayInfoEnemy();
    cout << endl;

    character.displayInfoCharacter();

    /*
        [Output]
        
        Name: Hero
        Health: 100

        Name: Goblin
        Damage: 20

        Name: Adventurer
        Level: 5
    */

    return 0;
}