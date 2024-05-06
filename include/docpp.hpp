/**
 * docpp - Small C++ library for generating XML, HTML and CSS.
 * Licensed under the LGPL-3.0-or-later license.
 *
 * Author: speedie <speedie@speedie.site>
 *
 * @file docpp.hpp
 * @brief Header file for docpp
 * @author speedie
 * @date 2024
 * @copyright GNU Lesser General Public License 3.0
 * @version 0.0.1
 */
#pragma once

#include <string>
#include <vector>
#include <unordered_map>

/**
 * @brief A namespace to represent HTML elements and documents
 */
namespace docpp {
    namespace HTML {
        enum {
            SECTION_HTML,
            SECTION_HEAD,
            SECTION_BODY,
            SECTION_FOOTER,
            SECTION_DIV,
            TYPE_SELF_CLOSING,
            TYPE_NON_SELF_CLOSING,
            TYPE_NON_CLOSED,
            FORMATTING_NONE,
            FORMATTING_PRETTY,
        };

        /**
         * @brief A class to represent an HTML property
         */
        class HTMLProperty {
            private:
                std::pair<std::string, std::string> property{};
            protected:
            public:
                /**
                 * @brief The npos value
                 */
                static const int npos = -1;

                /**
                 * @brief Construct a new HTMLProperty object
                 * @param key The key of the property
                 * @param value The value of the property
                 */
                HTMLProperty(const std::string& key, const std::string& value);
                /**
                 * @brief Construct a new HTMLProperty object
                 * @param property The property to set
                 */
                HTMLProperty(const std::pair<std::string, std::string>& property);
                HTMLProperty() = default;

                /**
                 * @brief Get the key of the property
                 * @return std::string The key of the property
                 */
                std::string getKey() const;
                /**
                 * @brief Get the value of the property
                 * @return std::string The value of the property
                 */
                std::string getValue() const;
                /**
                 * @brief Get the property.
                 * @return std::pair<std::string, std::string> The value of the property
                 */
                std::pair<std::string, std::string> get() const;
                /**
                 * @brief Set the key of the property.
                 * @param key The key.
                 */
                void setKey(const std::string& key);
                /**
                 * @brief Set the value of the property.
                 * @param value The value.
                 */
                void setValue(const std::string& value);
                /**
                 * @brief Set the property
                 * @param property The property.
                 */
                void set(const std::pair<std::string, std::string>& property);
        };

        /**
         * @brief A class to represent the properties of an HTML element
         */
        class HTMLElementProperties {
            private:
                std::vector<HTMLProperty> properties{};
            protected:
            public:
                /**
                 * @brief The npos value
                 */
                static const int npos = -1;

                /**
                 * @brief Get the properties of the element
                 * @return std::vector<HTMLProperty> The properties of the element
                 */
                std::vector<HTMLProperty> getProperties() const;
                /**
                 * @brief Set the properties of the element
                 * @param properties The properties to set
                 */
                void set(const std::vector<HTMLProperty>& properties);
                /**
                 * @brief Get the property at an index
                 * @param index The index of the property
                 * @return HTMLProperty The property at the index
                 */
                HTMLProperty at(const int index) const;
                /**
                 * @brief Insert a property into the element
                 * @param index The index to insert the property
                 * @param property The property to insert
                 */
                void insert(const int index, const HTMLProperty& property);
                /**
                 * @brief Erase a property from the element
                 * @param index The index of the property to erase
                 */
                void erase(const int index);
                /**
                 * @brief Find a property in the element
                 * @param property The property to find
                 * @return int The index of the property
                 */
                int find(const HTMLProperty& property);
                /**
                 * @brief Find a property in the element
                 * @param str The property to find
                 * @return int The index of the property
                 */
                int find(const std::string& str);
                /**
                 * @brief Swap two properties in the element
                 * @param index1 The index of the first property
                 * @param index2 The index of the second property
                 */
                void swap(const int index1, const int index2);
                /**
                 * @brief Swap two properties in the element
                 * @param property1 The first property
                 * @param property2 The second property
                 */
                void swap(const HTMLProperty& property1, const HTMLProperty& property2);
                /**
                 * @brief Get the size of the element
                 * @return int The size of the element
                 */
                int size() const;
                /**
                 * @brief Prepend a property to the element
                 * @param property The property to add
                 */
                void push_front(const HTMLProperty& property);
                /**
                 * @brief Append a property to the element
                 * @param property The property to add
                 */
                void push_back(const HTMLProperty& property);
                /**
                 * @brief Construct a new HTMLElementProperties object
                 * @param properties The properties to set
                 */
                HTMLElementProperties(const std::vector<HTMLProperty>& properties);
                /**
                 * @brief Construct a new HTMLElementProperties object
                 * @param property The property to add
                 */
                HTMLElementProperties(const HTMLProperty& property);
                /**
                 * @brief Construct a new HTMLElementProperties object
                 */
                HTMLElementProperties() = default;
                HTMLElementProperties operator=(const HTMLElementProperties& properties);
                HTMLElementProperties operator=(const std::vector<HTMLProperty>& properties);
                HTMLElementProperties operator=(const HTMLProperty& property);
                void operator+=(const HTMLProperty& property);
        };

        /**
         * @brief A class to represent an HTML element
         */
        class HTMLElement {
            private:
                std::string tag{};
                std::string data{};
                int type{TYPE_NON_SELF_CLOSING};
                HTMLElementProperties properties{};
            protected:
            public:
                /**
                 * @brief The npos value
                 */
                static const int npos = -1;

                /**
                 * @brief Construct a new HTMLElement object
                 * @param tag The tag of the element
                 * @param properties The properties of the element
                 * @param data The data of the element
                 */
                HTMLElement(const std::string& tag, const HTMLElementProperties& properties = {}, const std::string& data = {}, const int type = TYPE_NON_SELF_CLOSING);
                /**
                 * @brief Construct a new HTMLElement object
                 */
                HTMLElement() = default;
                /**
                 * @brief Set the tag, id, and classes of the element
                 * @param tag The tag of the element
                 * @param id The id of the element
                 * @param classes The classes of the element
                 */
                void set(const std::string& tag, const HTMLElementProperties& properties = {}, const std::string& data = {}, const int type = TYPE_NON_SELF_CLOSING);

                /**
                 * @brief Get the element in the form of an HTML tag.
                 * @return std::string The tag of the element
                 */
                std::string get(const int formatting = FORMATTING_NONE) const;

                /**
                 * @brief Get the tag of the element
                 * @return std::string The data of the element
                 */
                std::string getTag() const;

                /**
                 * @brief Get the data of the element
                 * @return std::string The data of the element
                 */
                std::string getData() const;
                HTMLElement operator=(const HTMLElement& element);
                void operator+=(const std::string& data);
        };

        /**
         * @brief A class to represent an HTML section (head, body, etc.)
         */
        class HTMLSection {
            private:
                int index{};
                std::string tag{};
                HTMLElementProperties properties{};

                std::unordered_map<int, HTMLElement> elements{};
                std::unordered_map<int, HTMLSection> sections{};
            protected:
            public:
                /**
                 * @brief The npos value
                 */
                static const int npos = -1;

                /**
                 * @brief Prepend an element to the section
                 * @param element The element to add
                 */
                void push_front(const HTMLElement& element);
                /**
                 * @brief Prepend a section to the section
                 * @param section The section to add
                 */
                void push_front(const HTMLSection& section);
                /**
                 * @brief Append an element to the section
                 * @param element The element to add
                 */
                void push_back(const HTMLElement& element);
                /**
                 * @brief Append a section to the section
                 * @param section The section to add
                 */
                void push_back(const HTMLSection& section);
                /**
                 * @brief Get the element at an index. To get a section, use at_section()
                 * @param index The index of the element
                 * @return HTMLElement The element at the index
                 */
                HTMLElement at(const int index) const;
                /**
                 * @brief Get the section at an index. To get an element, use at()
                 * @param index The index of the section
                 * @return HTMLSection The section at the index
                 */
                HTMLSection at_section(const int index) const;
                /**
                 * @brief Erase an element from the section. Note that this will NOT change the size/index.
                 * @param index The index of the element to erase
                 */
                void erase(const int index);
                /**
                 * @brief Erase a section from the section, by reading from a section. The section will be erased if it's identical to section. Note that this will NOT change the size/index.
                 * @param section The section to erase
                 */
                void erase(const HTMLSection& section);
                /**
                 * @brief Erase an element from the section, by reading from an element. The element will be erased if it's identical to element. Note that this will NOT change the size/index.
                 * @param element The element to erase
                 */
                void erase(const HTMLElement& element);
                /**
                 * @brief Find an element in the section
                 * @param element The element to find
                 * @return int The index of the element
                 */
                int find(const HTMLElement& element);
                /**
                 * @brief Find a section in the section
                 * @param section The section to find
                 * @return int The index of the section
                 */
                int find(const HTMLSection& section);
                /**
                 * @brief Find an element or section in the section
                 * @param str The element or section to find
                 * @return int The index of the element or section
                 */
                int find(const std::string& str);
                /**
                 * @brief Insert an element into the section
                 * @param index The index to insert the element
                 * @param element The element to insert
                 */
                void insert(const int index, const HTMLElement& element);
                /**
                 * @brief Insert a section into the section
                 * @param index The index to insert the section
                 * @param section The section to insert
                 */
                void insert(const int index, const HTMLSection& section);
                /**
                 * @brief Get the size of the section
                 * @return int The size of the section
                 */
                int size() const;

                /**
                 * @brief Construct a new HTMLSection object
                 * @param tag The tag of the section
                 * @param properties The properties of the section
                 */
                HTMLSection(const std::string& tag, const HTMLElementProperties& properties = {});
                /**
                 * @brief Construct a new HTMLSection object
                 * @param tag The tag of the section
                 * @param properties The properties of the section
                 */
                HTMLSection(const int tag, const HTMLElementProperties& properties = {});
                /**
                 * @brief Construct a new HTMLSection object
                 */
                HTMLSection() = default;
                /**
                 * @brief Set the tag, id, and classes of the section
                 * @param tag The tag of the section
                 * @param id The id of the section
                 * @param classes The classes of the section
                 */
                void set(const std::string& tag, const HTMLElementProperties& properties = {});
                /**
                 * @brief Set the tag, id, and classes of the section
                 * @param tag The tag of the section
                 * @param id The id of the section
                 * @param classes The classes of the section
                 */
                void set(const int tag, const HTMLElementProperties& properties = {});
                /**
                 * @brief Swap two elements in the section
                 * @param index1 The index of the first element
                 * @param index2 The index of the second element
                 */
                void swap(const int index1, const int index2);
                /**
                 * @brief Swap two elements in the section
                 * @param element1 The first element
                 * @param element2 The second element
                 */
                void swap(const HTMLElement& element1, const HTMLElement& element2);
                /**
                 * @brief Swap two sections in the section
                 * @param index1 The index of the first section
                 * @param index2 The index of the second section
                 */
                void swap(const HTMLSection& section1, const HTMLSection& section2);
                /**
                 * @brief Get the elements of the section
                 * @return std::vector<HTMLElement> The elements of the section
                 */
                std::vector<HTMLElement> getHTMLElements() const;
                /**
                 * @brief Get the sections of the section
                 * @return std::vector<HTMLSection> The sections of the section
                 */
                std::vector<HTMLSection> getHTMLSections() const;

                /**
                 * @brief Dump the entire section.
                 * @return std::string The section
                 */
                std::string get(const int formatting = FORMATTING_NONE) const;

                HTMLSection operator=(const HTMLSection& section);
                void operator+=(const HTMLElement& element);
                void operator+=(const HTMLSection& section);
                HTMLElement operator[](const int& index) const;
        };

        /**
         * @brief A class to represent an HTML document
         */
        class HTMLDocument {
            private:
                std::string doctype{"<!DOCTYPE html>"};
                HTMLSection document{};
            protected:
            public:
                /**
                 * @brief The npos value
                 */
                static const int npos = -1;

                /**
                 * @brief Get the document
                 * @param std::string The type to return
                 * @return std::string The document
                 */
                std::string get(const int formatting = FORMATTING_NONE) const;

                /**
                 * @brief Get the section
                 * @return HTMLSection The section
                 */
                HTMLSection& getSection();

                /**
                 * @brief Get the doctype of the document
                 * @return std::string The doctype of the document
                 */
                std::string getDoctype() const;

                /**
                 * @brief Set the document
                 * @param document The document to set
                 */
                void set(const HTMLSection& document);
                /**
                 * @brief Set the doctype of the document
                 * @param doctype The doctype to set
                 */
                void setDoctype(const std::string& doctype);
                /**
                 * @brief Construct a new HTMLDocument object
                 */
                HTMLDocument() = default;
                /**
                 * @brief Construct a new HTMLDocument object
                 * @param document The document to set
                 */
                HTMLDocument(const HTMLSection& document, const std::string& doctype = "<!DOCTYPE html>");

                HTMLDocument operator=(const HTMLDocument& document);
                HTMLDocument operator=(const HTMLSection& section);
        };
    } // namespace HTML

    namespace CSS {
        enum {
            FORMATTING_NONE,
            FORMATTING_PRETTY,
        };

        class CSSProperty {
            private:
                std::pair<std::string, std::string> property{};
            protected:
            public:
                /**
                 * @brief The npos value
                 */
                static const int npos = -1;

                /**
                 * @brief Construct a new CSSProperty object
                 * @param key The key of the property
                 * @param value The value of the property
                 */
                CSSProperty(const std::string& key, const std::string& value);
                /**
                 * @brief Construct a new CSSProperty object
                 * @param property The property to set
                 */
                CSSProperty(const std::pair<std::string, std::string>& property);
                CSSProperty() = default;

                /**
                 * @brief Get the key of the property
                 * @return std::string The key of the property
                 */
                std::string getKey() const;
                /**
                 * @brief Get the value of the property
                 * @return std::string The value of the property
                 */
                std::string getValue() const;
                /**
                 * @brief Get the property.
                 * @return std::pair<std::string, std::string> The value of the property
                 */
                std::pair<std::string, std::string> get() const;
                /**
                 * @brief Set the key of the property.
                 * @param key The key.
                 */
                void setKey(const std::string& key);
                /**
                 * @brief Set the value of the property.
                 * @param value The value.
                 */
                void setValue(const std::string& value);
                /**
                 * @brief Set the property
                 * @param property The property.
                 */
                void set(const std::pair<std::string, std::string>& property);
                /**
                 * @brief Set the property
                 * @param key The key of the property
                 * @param value The value of the property
                 */
                void set(const std::string& key, const std::string& value);

                CSSProperty operator=(const CSSProperty& property);
                CSSProperty operator=(const std::pair<std::string, std::string>& property);
        };

        class CSSElement {
            private:
                std::pair<std::string, std::vector<CSSProperty>> element{};
            protected:
            public:
                /**
                 * @brief The npos value
                 */
                static const int npos = -1;

                /**
                 * @brief Construct a new CSSElement object
                 * @param tag The tag of the element
                 * @param properties The properties of the element
                 */
                CSSElement(const std::string& tag, const std::vector<CSSProperty>& properties);
                /**
                 * @brief Construct a new CSSElement object
                 * @param element The element to set
                 */
                CSSElement(const std::pair<std::string, std::vector<CSSProperty>>& element);
                CSSElement() = default;

                /**
                 * @brief Prepend a property to the element
                 * @param property The property to push
                 */
                void push_front(const CSSProperty& property);
                /**
                 * @brief Append a property to the element
                 * @param property The property to push
                 */
                void push_back(const CSSProperty& property);
                /**
                 * @brief Insert a property into the element
                 * @param index The index to insert the property
                 * @param property The property to insert
                 */
                void insert(const int index, const CSSProperty& property);
                /**
                 * @brief Erase a property from the element
                 * @param index The index of the property to erase
                 */
                void erase(const int index);
                /**
                 * @brief Find a property in the element
                 * @param property The property to find
                 * @return int The index of the property
                 */
                int find(const CSSProperty& property);
                /**
                 * @brief Get the property at an index
                 * @param index The index of the property
                 * @return CSSProperty The property at the index
                 */
                CSSProperty at(const int index) const;
                /**
                 * @brief Find a property in the element
                 * @param str The property to find
                 * @return int The index of the property
                 */
                int find(const std::string& str);
                /**
                 * @brief Swap two properties in the element
                 * @param index1 The index of the first property
                 * @param index2 The index of the second property
                 */
                void swap(const int index1, const int index2);
                /**
                 * @brief Swap two properties in the element
                 * @param property1 The first property
                 * @param property2 The second property
                 */
                void swap(const CSSProperty& property1, const CSSProperty& property2);
                /**
                 * @brief Get the size of the element
                 * @return int The size of the element
                 */
                int size() const;
                /**
                 * @brief Set the properties of the element
                 * @param properties The properties to set
                 */
                void set(const std::string& tag, const std::vector<CSSProperty>& properties);
                /**
                 * @brief Set the properties of the element
                 * @param element The element to set
                 */
                void set(const std::pair<std::string, std::vector<CSSProperty>>& element);
                /**
                 * @brief Get the element
                 * @return std::pair<std::string, std::vector<CSSProperty>> The element
                 */
                std::string get(const int formatting = FORMATTING_NONE) const;
                /**
                 * @brief Get the tag of the element
                 * @return std::string The tag of the element
                 */
                std::string getTag() const;
                /**
                 * @brief Get the properties of the element
                 * @return std::vector<CSSProperty> The properties of the element
                 */
                std::vector<CSSProperty> getProperties() const;

                CSSElement operator=(const CSSElement& element);
                CSSElement operator=(const std::pair<std::string, std::vector<CSSProperty>>& element);
                void operator+=(const CSSProperty& property);
                CSSProperty operator[](const int& index) const;
        };

        /**
         * @brief A class to represent a CSS stylesheet
         */
        class CSSStylesheet {
            private:
                std::vector<CSSElement> elements{};
            protected:
            public:
                /**
                 * @brief The npos value
                 */
                static const int npos = -1;

                /**
                 * @brief Construct a new CSSStylesheet object
                 * @param elements The elements to set
                 */
                CSSStylesheet(const std::vector<CSSElement>& elements);
                CSSStylesheet() = default;

                /**
                 * @brief Prepend an element to the stylesheet
                 * @param element The element to add
                 */
                void push_front(const CSSElement& element);
                /**
                 * @brief Append an element to the stylesheet
                 * @param element The element to add
                 */
                void push_back(const CSSElement& element);
                /**
                 * @brief Insert an element into the stylesheet
                 * @param index The index to insert the element
                 * @param element The element to insert
                 */
                void insert(const int index, const CSSElement& element);
                /**
                 * @brief Erase an element from the stylesheet. Note that this will NOT change the size/index.
                 * @param index The index of the element to erase
                 */
                void erase(const int index);
                /**
                 * @brief Find an element in the stylesheet
                 * @param element The element to find
                 * @return int The index of the element
                 */
                int find(const CSSElement& element);
                /**
                 * @brief Find an element in the stylesheet
                 * @param str The element to find, either the tag or the stylesheet itself
                 * @return int The index of the element
                 */
                int find(const std::string& str);
                /**
                 * @brief Get the element at an index
                 * @param index The index of the element
                 * @return CSSElement The element at the index
                 */
                CSSElement at(const int index) const;
                /**
                 * @brief Get the size of the stylesheet
                 * @return int The size of the stylesheet
                 */
                int size() const;
                /**
                 * @brief Swap two elements in the stylesheet
                 * @param index1 The index of the first element
                 * @param index2 The index of the second element
                 */
                void swap(const int index1, const int index2);
                /**
                 * @brief Swap two elements in the stylesheet
                 * @param element1 The first element
                 * @param element2 The second element
                 */
                void swap(const CSSElement& element1, const CSSElement& element2);
                /**
                 * @brief Set the elements of the stylesheet
                 * @param elements The elements to set
                 */
                void set(const std::vector<CSSElement>& elements);
                /**
                 * @brief Get the elements of the stylesheet
                 * @return std::vector<CSSElement> The elements of the stylesheet
                 */
                std::vector<CSSElement> getElements() const;
                /**
                 * @brief Get the stylesheet
                 * @return std::string The stylesheet
                 */
                std::string get(const int formatting = FORMATTING_NONE) const;

                CSSStylesheet operator=(const CSSStylesheet& stylesheet);
                void operator+=(const CSSElement& element);
                CSSElement operator[](const int& index) const;
        };
    }
}
