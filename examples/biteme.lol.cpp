/**
 * @file biteme.lol.cpp
 * @brief A simple program that replicates biteme.lol using docpp.
 * @details This program creates a simple HTML document that replicates the biteme.lol website.
 * @see https://biteme.lol
 * @license LGPL-3.0
 *
 * g++ -std=c++11 biteme.lol.cpp -o biteme.lol -ldocpp
 */
#include <fstream>
#include <docpp/docpp.hpp>

int main() {
    docpp::HTML::Section html(docpp::HTML::Tag::Html, {});

    html.push_back({"title", {}, "Google"});

    docpp::CSS::Stylesheet sheet{{
        {".center", {
            {"display", "flex"},
            {"flex-wrap", "wrap"},
            {"justify-content", "center"},
            {"align-items", "center"},
            {"font-size", "10vw"},
            {"height", "10vw"},
            {"padding", "10vw"},
        }},
        {"input[type=text], select", {
            {"width", "50vw"},
        }},
    }};

    html.push_back({"style", {}, sheet.get(docpp::CSS::Formatting::Pretty)});

    docpp::HTML::Section div{docpp::HTML::Tag::Div, {docpp::HTML::Property("class", "center")}};

    div.push_back({"font", {docpp::HTML::Property("color", "blue")}, "G"});
    div.push_back({"font", {docpp::HTML::Property("color", "red")}, "o"});
    div.push_back({"font", {docpp::HTML::Property("color", "yellow")}, "o"});
    div.push_back({"font", {docpp::HTML::Property("color", "blue")}, "g"});
    div.push_back({"font", {docpp::HTML::Property("color", "green")}, "l"});
    div.push_back({"font", {docpp::HTML::Property("color", "red")}, "e"});

    html.push_back(div);

    docpp::HTML::Section div2{docpp::HTML::Tag::Div, {docpp::HTML::Property("align", "center")}};
    docpp::HTML::Section form{"form", {{docpp::HTML::Property("action", "https://google.com/search"), docpp::HTML::Property("method", "get")}}};

    form.push_back({"input", docpp::HTML::Properties({docpp::HTML::Property("type", "text"), docpp::HTML::Property("name", "q")}), "", docpp::HTML::Type::Self_Closing});
    form.push_back({"input", docpp::HTML::Properties({docpp::HTML::Property("type", "submit"), docpp::HTML::Property("value", "Search!")}), "", docpp::HTML::Type::Self_Closing});

    div2.push_back(form);
    html.push_back(div2);

    docpp::HTML::Document doc{html};

    std::ofstream file("biteme.lol.html");

    file << doc.get(docpp::HTML::Formatting::Pretty);

    file.close();

    return 0;
}
