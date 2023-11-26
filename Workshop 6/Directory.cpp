

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <string>
#include <algorithm>
#include "Directory.h"
using namespace std;

namespace sdds {
	Directory::Directory(const std::string& name)
	{
		m_name = name;
	}

	void Directory::update_parent_path(const std::string& path)
	{
		m_parent_path = path;
		for (auto item : m_contents)
		{
			item->update_parent_path(path + m_name);
		}
	}

	std::string Directory::path() const
	{
		return m_parent_path + m_name;
	}

	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	std::string Directory::name() const {
		return m_name;
	}

	int Directory::count() const {
		return (int)m_contents.size();
	}

	size_t Directory::size() const {
		size_t total = 0u;
		for (Resource* res : m_contents) {
			if (res) {
				total += res->size();
			}
		}
		return total;
	}

	Directory& Directory::operator+=(Resource* resource) {
		for (Resource* res : m_contents) {
			if (res) {
				if (res->name() == resource->name()) {
					throw std::runtime_error("Resource with the same name already exists in the directory.");
				}
			}
		}
		m_contents.push_back(resource);
		resource->update_parent_path(m_parent_path + m_name);
		return *this;
	}

	Resource* Directory::find(const std::string& resourceName, const std::vector<OpFlags>& flags) {
		// Check if the RECURSIVE flag is set
		bool isRecursive = std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end();


		// Search for the resource in the directory
		for (Resource* resource : m_contents) {
			if (resource && resource->name() == resourceName) {
				return resource;
			}

			// If the resource is a directory and the RECURSIVE flag is set, recursively search within that directory
			if (isRecursive && resource && resource->type() == NodeType::DIR) {
				Directory* subDirectory = dynamic_cast<Directory*>(resource);
				if (subDirectory) {
					Resource* foundResource = subDirectory->find(resourceName, flags);
					if (foundResource) {
						return foundResource;
					}
				}
			}
		}

		return nullptr; // Resource not found
	}

	Directory::~Directory() {
		for (Resource* resource : m_contents) {
			delete resource;
		}
	}

	void Directory::remove(const std::string& name, const std::vector<OpFlags>& flags) {
		bool isRecursive = std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end();

		Resource* resource = find(name, {});

		if (!resource) {
			throw std::string(name + " does not exist in " + m_name + ".");
		}

		if (resource->type() == NodeType::DIR && !isRecursive) {
			throw std::invalid_argument(name + " is a directory. Pass the recursive flag to delete directories.");
		}

		m_contents.erase(std::remove(m_contents.begin(), m_contents.end(), resource), m_contents.end());
		delete resource;
	}


	void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flags) const
	{
		bool longFlag = false;
		for (auto flag : flags)
			if (flag == FormatFlags::LONG)
				longFlag = true;

		os << "Total size: " << std::setw(2) << size() << " bytes\n";

		for (auto res : m_contents)
		{
			if (res->type() == NodeType::FILE)
			{
				os << "F | ";
			}
			else if (res->type() == NodeType::DIR)
			{
				os << "D | ";
			}
			os << std::setw(15) << std::setiosflags(std::ios::left) << res->name() << std::setiosflags(std::ios::left) << " |";
			if (longFlag)
			{
				if (res->type() == NodeType::FILE)
				{
					os << "  " << std::setw(2) << "" << "|" << std::setw(5) << std::setiosflags(std::ios::right) << res->size() << std::resetiosflags(std::ios::right) << " bytes | \n";
				}
				else if (res->type() == NodeType::DIR)
				{
					os << "  " << std::setw(2) << res->count() << "|" << std::setw(5) << std::setiosflags(std::ios::right) << res->size() << std::resetiosflags(std::ios::right) << " bytes | \n";
				}
				//os << std::resetiosflags(std::ios::right) << "";
			}
			else
				os << std::endl;
		}
	}
}
