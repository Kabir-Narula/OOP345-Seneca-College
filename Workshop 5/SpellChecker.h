

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#define SIZE 6
namespace sdds {
class SpellChecker {
    std::string m_badWords[SIZE];
    std::string m_goodWords[SIZE];
    static size_t m_numReplaced[SIZE];
public:
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& out) const;
    
};
}

#endif /* SpellChecker_h */
