/*Design a Book class with attributes such as title, 
author, and ISBN. Include methods that allow setting and getting these attributes. 
In the main function, create an instance of the Book class and 
demonstrate setting and retrieving its attributes.*/
#include <iostream>
#include <string>

class Book
{
    private:
        std::string author;
        std::string title;
        std::string ISBN;
    public:
        Book(std::string s1,std::string s2,std::string s3) : author(s1) , title(s2) , ISBN(s3) {}
        std::string get_author()
        {
            return author;
        }
        std::string get_title()
        {
            return title;
        }
        std::string get_ISBN()
        {
            return ISBN;
        }
        void set_author(std::string s1)
        {
            author = s1;
        }
        void set_title(std::string s1)
        {
            title = s1;
        }
        void set_ISBN(std::string s1)
        {
            ISBN = s1;
        }
};

int main()
{
    Book book1("Anush" , "txur patmutyun" , "liqy ankap tver");
    Book book2("Anna" , "Annayi kyanqi patmutyuny", "eli ankap tver");
    std::cout << book1.get_author() << "  " << book1.get_title() << "  " <<book1.get_ISBN() << std::endl;
    book2.set_author("el hexinaky Annan chi");
    std::cout << book2.get_author() << "  " << book2.get_title() << "  " <<book2.get_ISBN() << std::endl;
}