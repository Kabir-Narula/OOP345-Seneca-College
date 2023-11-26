// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

#include <string>
#include <fstream>
#include <vector>
#include "Filesystem.h"
#include "Directory.h"
#include "File.h"

using namespace std;
namespace sdds
{
	void Filesystem::addResource(std::string& path, const std::string& content)
	{
		bool done = false;
		Directory* current = m_root;
		do
		{
			done = path.find("/") == string::npos;
			if (!done)
			{
				string dirName = path.substr(0, path.find("/") + 1);
				Directory* newDir = nullptr;
				path = path.substr(path.find("/") + 1);
				newDir = dynamic_cast<Directory*>(m_root->find(dirName));

				if (!newDir)
				{
					newDir = new Directory(dirName);
					*current += newDir;
				}
				current = newDir;
			}
			else if (content.length() && !m_root->find(path))
			{
				*current += new File(path.c_str(), content.c_str());
			}

		} while (!done);
	}

	Filesystem::Filesystem(const char* fileName, const std::string& root)
	{
		m_root = new Directory(root);
		m_current = m_root;

		fstream file(fileName);
		if (file)
		{
			string line{};
			do
			{
				bool isFile{};
				getline(file, line);

				isFile = line.find('|') != string::npos;

				if (isFile)
				{
					string path = line.substr(0, line.find('|'));
					trimString(path);
					string contents = line.substr(line.find('|') + 1);
					trimString(contents);
					addResource(path, contents);
				}
				else
				{
					trimString(line);
					addResource(line);
				}

			} while (file);
		}
		else
		{
			delete m_root;
			throw "ERROR READING FILE";
		}
	}

	Filesystem::Filesystem(Filesystem&& other) noexcept
	{
		*this = std::move(other);
	}

	Filesystem& Filesystem::operator=(Filesystem&& other) noexcept
	{
		if (this != &other)
		{
			delete m_root;
			m_root = other.m_root;
			delete other.m_root;
			other.m_current = nullptr;
			m_current = m_root;
		}
		return *this;
	}

	Filesystem& Filesystem::operator+=(Resource* res)
	{
		*m_current += res;
		return *this;
	}

	Directory* Filesystem::change_directory(const std::string& dirName)
	{
		if (dirName.length())
		{
			Resource* targetDir = m_root->find(dirName, vector<OpFlags>{OpFlags::RECURSIVE});
			if (targetDir && targetDir->type() == NodeType::DIR)
			{
				m_current = dynamic_cast<Directory*>(targetDir);
			}
			else
			{
				throw std::invalid_argument("Cannot change directory! " + dirName + " not found!");
			}
		}
		else
		{
			m_current = m_root;
		}
		return m_current;
	}

	Directory* Filesystem::get_current_directory() const
	{
		return m_current;
	}

	Filesystem::~Filesystem()
	{
		delete m_root;
		m_current = nullptr;
	}

	void trimString(std::string& source)
	{
		size_t begin = source.find_first_not_of(" \t\n");
		size_t end = source.find_last_not_of(" \t\n");
		string res{};
		if (begin != string::npos && end != string::npos)
		{
			res = source.substr(begin, end - begin + 1);
		}
		else
		{
			res = "";
		}
		source = res;
	}
}
