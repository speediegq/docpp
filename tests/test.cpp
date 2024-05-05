#include <string>
#include <include/docpp.hpp>
#include <src/docpp.cpp>
#include <catch2/catch_test_macros.hpp>

/**
 * @brief Test cases for the DuvaHTML namespace.
 */
SCENARIO("Test HTML", "[HTML]") {
    auto test1 = []() {
        docpp::HTML::HTMLDocument doc{};
        docpp::HTML::HTMLSection html(docpp::HTML::SECTION_HTML, {});

        docpp::HTML::HTMLSection head(docpp::HTML::SECTION_HEAD, {});
        docpp::HTML::HTMLSection body(docpp::HTML::SECTION_BODY, {});
        docpp::HTML::HTMLSection div(docpp::HTML::SECTION_DIV, {});
        docpp::HTML::HTMLSection footer(docpp::HTML::SECTION_FOOTER, {});

        head.push_back(docpp::HTML::HTMLElement("title", {}, "Test Title"));
        body.push_back(docpp::HTML::HTMLElement("h1", {}, "Test Header"));
        body.push_back(docpp::HTML::HTMLElement("p", {}, "Test Paragraph"));

        docpp::HTML::HTMLElementProperties prop{};
        prop.push_back(docpp::HTML::HTMLProperty(std::pair<std::string, std::string>("id", "test_id")));

        body.push_back(docpp::HTML::HTMLElement("p", prop, "Test Paragraph With ID"));

        div.push_back(docpp::HTML::HTMLElement("p", {}, "Test Paragraph In Div"));
        body.push_back(div);

        prop.push_back(docpp::HTML::HTMLProperty(std::pair<std::string, std::string>("class", "class1 class2 class3")));

        body.push_back(docpp::HTML::HTMLElement("p", prop, "Test Paragraph With ID And Class"));

        html.push_back(head);
        html.push_back(body);
        html.push_back(footer);

        doc.set(html);

        const std::string expected_html{"<!DOCTYPE html><html><head><title>Test Title</title></head><body><h1>Test Header</h1><p>Test Paragraph</p><p id=\"test_id\">Test Paragraph With ID</p><div><p>Test Paragraph In Div</p></div><p id=\"test_id\" class=\"class1 class2 class3\">Test Paragraph With ID And Class</p></body><footer></footer></html>"};

        REQUIRE(doc.get() == expected_html);
        REQUIRE(doc.get(docpp::HTML::FORMATTING_PRETTY) == "<!DOCTYPE html>\n<html>\n<head>\n<title>Test Title</title>\n</head>\n<body>\n<h1>Test Header</h1>\n<p>Test Paragraph</p>\n<p id=\"test_id\">Test Paragraph With ID</p>\n<div>\n<p>Test Paragraph In Div</p>\n</div>\n<p id=\"test_id\" class=\"class1 class2 class3\">Test Paragraph With ID And Class</p>\n</body>\n<footer>\n</footer>\n</html>");
    };

    auto test2 = []() {
        docpp::HTML::HTMLSection section(docpp::HTML::SECTION_HTML, {});

        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 1"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 2"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 3"));

        section.erase(docpp::HTML::HTMLElement("p", {}, "Test 2"));

        REQUIRE(section.get() == "<html><p>Test 1</p><p>Test 3</p></html>");
        REQUIRE(section.get(docpp::HTML::FORMATTING_PRETTY) == "<html>\n<p>Test 1</p>\n<p>Test 3</p>\n</html>");
    };

    auto test3 = []() {
        docpp::HTML::HTMLSection section = docpp::HTML::HTMLSection(docpp::HTML::SECTION_HTML, {});

        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 1"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 2"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 3"));

        int pos = section.find(docpp::HTML::HTMLElement("p", {}, "Test 2"));
        section.insert(pos, docpp::HTML::HTMLElement("p", {}, "Test 2.5"));

        REQUIRE(section.get() == "<html><p>Test 1</p><p>Test 2.5</p><p>Test 3</p></html>");
        REQUIRE(section.get(docpp::HTML::FORMATTING_PRETTY) == "<html>\n<p>Test 1</p>\n<p>Test 2.5</p>\n<p>Test 3</p>\n</html>");
    };

    auto test4 = []() {
        docpp::HTML::HTMLSection section = docpp::HTML::HTMLSection(docpp::HTML::SECTION_HTML, {});

        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 1"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 2"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 3"));

        int pos = section.find(docpp::HTML::HTMLElement("p", {}, "Test 2"));

        section.erase(pos);

        REQUIRE(section.get() == "<html><p>Test 1</p><p>Test 3</p></html>");
        REQUIRE(section.get(docpp::HTML::FORMATTING_PRETTY) == "<html>\n<p>Test 1</p>\n<p>Test 3</p>\n</html>");
    };

    auto test5 = []() {
        docpp::HTML::HTMLSection section = docpp::HTML::HTMLSection(docpp::HTML::SECTION_HTML, {});
        docpp::HTML::HTMLSection subsection(docpp::HTML::SECTION_DIV, {});

        subsection.push_back(docpp::HTML::HTMLElement("p", {}, "Test 1"));

        docpp::HTML::HTMLSection subsection2(docpp::HTML::SECTION_DIV, {});
        subsection2.push_back(docpp::HTML::HTMLElement("p", {}, "Test 2"));

        subsection.push_back(subsection2);

        section.push_back(subsection);

        docpp::HTML::HTMLDocument doc{};
        doc.set(section);

        REQUIRE(doc.get() == "<!DOCTYPE html><html><div><p>Test 1</p><div><p>Test 2</p></div></div></html>");
        REQUIRE(doc.get(docpp::HTML::FORMATTING_PRETTY) == "<!DOCTYPE html>\n<html>\n<div>\n<p>Test 1</p>\n<div>\n<p>Test 2</p>\n</div>\n</div>\n</html>");
    };

    auto test6 = []() {
        docpp::CSS::CSSStylesheet css{};
        docpp::CSS::CSSElement element{"p", {{"color", "red"}, {"font-size", "16px"}, {"font-family", "Arial"}}};

        css.push_back(element);

        REQUIRE(css.get() == "p {color: red;font-size: 16px;font-family: Arial;}");
        REQUIRE(css.get(docpp::CSS::FORMATTING_PRETTY) == "p {\ncolor: red;\nfont-size: 16px;\nfont-family: Arial;\n}\n");
    };

    auto test7 = []() {
        docpp::CSS::CSSStylesheet css = docpp::CSS::CSSStylesheet{};
        docpp::CSS::CSSElement element = docpp::CSS::CSSElement{"p", {{"color", "red"}, {"font-size", "16px"}, {"font-family", "Arial"}}};
        docpp::CSS::CSSElement element2{"div", {{"color", "blue"}, {"font-size", "12px"}, {"font-family", "Arial"}}};

        css.push_back(element);
        css.push_front(element2);

        REQUIRE(css.get() == "div {color: blue;font-size: 12px;font-family: Arial;}p {color: red;font-size: 16px;font-family: Arial;}");
    };

    auto test8 = []() {
        docpp::CSS::CSSStylesheet css = docpp::CSS::CSSStylesheet{};
        docpp::CSS::CSSElement element = docpp::CSS::CSSElement{"p", {{"color", "red"}, {"font-size", "16px"}, {"font-family", "Arial"}}};
        docpp::CSS::CSSElement element2{"div", {{"color", "blue"}, {"font-size", "12px"}, {"font-family", "Arial"}}};

        css.push_back(element);
        css.push_front(element2);

        css.erase(css.find(element2));

        REQUIRE(css.get() == "p {color: red;font-size: 16px;font-family: Arial;}");
    };

    auto test9 = []() {
        docpp::CSS::CSSStylesheet css = docpp::CSS::CSSStylesheet{};
        docpp::CSS::CSSElement element = docpp::CSS::CSSElement{"p", {{"color", "red"}, {"font-size", "16px"}, {"font-family", "Arial"}}};
        docpp::CSS::CSSElement element2{"div", {{"color", "blue"}, {"font-size", "12px"}, {"font-family", "Arial"}}};

        css.push_back(element);
        css.push_front(element2);

        css.erase(css.find(element2));
        css.push_front(element2);

        css.swap(css.find(element), css.find(element2));

        REQUIRE(css.get() == "p {color: red;font-size: 16px;font-family: Arial;}div {color: blue;font-size: 12px;font-family: Arial;}");
    };

    auto test10 = []() {
        docpp::HTML::HTMLSection section = docpp::HTML::HTMLSection(docpp::HTML::SECTION_HTML, {});

        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 1"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 2"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 3"));

        section.swap(section.find(docpp::HTML::HTMLElement("p", {}, "Test 2")), section.find(docpp::HTML::HTMLElement("p", {}, "Test 3")));

        REQUIRE(section.get() == "<html><p>Test 1</p><p>Test 3</p><p>Test 2</p></html>");
    };

    auto test11 = []() {
        docpp::HTML::HTMLSection section = docpp::HTML::HTMLSection(docpp::HTML::SECTION_HTML, {});

        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 1"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 2"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 3"));

        section.swap(docpp::HTML::HTMLElement("p", {}, "Test 2"), docpp::HTML::HTMLElement("p", {}, "Test 3"));

        REQUIRE(section.get() == "<html><p>Test 1</p><p>Test 3</p><p>Test 2</p></html>");
    };

    auto test12 = []() {
        docpp::HTML::HTMLSection section = docpp::HTML::HTMLSection(docpp::HTML::SECTION_HTML, {});

        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 1"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 2"));
        section.push_back(docpp::HTML::HTMLElement("p", {}, "Test 3"));

        section.push_front(docpp::HTML::HTMLElement("p", {}, "Test 0"));

        REQUIRE(section.get() == "<html><p>Test 0</p><p>Test 1</p><p>Test 2</p><p>Test 3</p></html>");
    };

    std::vector<void (*)()> tests{test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11, test12};

    for (const auto& test : tests) {
        test();
    }
}
