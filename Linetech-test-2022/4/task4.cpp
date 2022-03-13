#include <iostream>
#include <type_traits>

using namespace std;

template <typename n>
class TemplateClass {
    private:
        n x;

    public:
        TemplateClass(n xx) {
            x = xx;
        }
        n getX(){
            return x;
        }
};

int main() {
    int i = 0;

    //checking if template works
    TemplateClass <int> a(23);
    cout << "constructor " << a.getX() << endl;

    //checking if is copy and move assignable/constructable
    cout << boolalpha;
    cout << "is move constructable " << std::is_move_constructible_v<TemplateClass<int>> <<endl;
    cout << "is move assignable " << std::is_move_assignable_v<TemplateClass<int>> <<endl;
    cout << "is copy constructable " << std::is_copy_constructible_v<TemplateClass<int>> <<endl;
    cout << "is copy assignable " << std::is_copy_assignable_v<TemplateClass<int>> <<endl;
    
    return 0;
}