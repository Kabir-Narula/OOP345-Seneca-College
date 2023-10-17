// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
namespace sdds{
class Movie{
    std::string m_title;
    size_t m_year;
    std::string m_desc;
public:
    Movie();
    const std::string& title() const;
    Movie(const std::string& strMovie);
    template <typename T>
    void fixSpelling(T& spellChecker){
        spellChecker(m_title);
        spellChecker(m_desc);
    }
    std::string removeSpaces(std::string& str);
    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
};
}

#endif /* Movie_hpp */
