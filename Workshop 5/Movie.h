

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
