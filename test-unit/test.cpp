#include "../src/main.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


//Testing incorrect inputs using the Insert() function
TEST_CASE("Base Case", "[base_case]"){

	AdjacencyList graph;
	graph.addTo("google.com", "gmail.com");
	graph.addTo("google.com", "maps.com");
	graph.addTo("facebook.com", "ufl.edu");
	graph.addTo("ufl.edu", "google.com");
	graph.addTo("ufl.edu", "gmail.com");
	graph.addTo("maps.com", "facebook.com");
	graph.addTo("gmail.com", "maps.com");
	std::vector<string> actualOutput = graph.testOut(2);
	std::vector<string> expectedOutput = { "facebook.com 0.20", "gmail.com 0.20", "google.com 0.10", "maps.com 0.30", "ufl.edu 0.20" };
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

//Testing edge cases with Remove(), RemoveInorder(), and SearchID()
TEST_CASE("Only One Vertex", "[one_vertex]") {

	AdjacencyList graph;
	graph.addTo("google.com", "google.com");
	std::vector<string> actualOutput = graph.testOut(1);
	std::vector<string> expectedOutput = { "google.com 1.00" };
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

//Testing the four types of rotations
TEST_CASE("Points to Itself", "[self]") {

	AdjacencyList graph;
	graph.addTo("google.com", "gmail.com");
	graph.addTo("google.com", "maps.com");
	graph.addTo("facebook.com", "ufl.edu");
	graph.addTo("ufl.edu", "ufl.edu");
	graph.addTo("ufl.edu", "gmail.com");
	graph.addTo("maps.com", "facebook.com");
	graph.addTo("gmail.com", "maps.com");
	std::vector<string> actualOutput = graph.testOut(3);
	std::vector<string> expectedOutput = { "facebook.com 0.30", "gmail.com 0.15", "google.com 0.00", "maps.com 0.20", "ufl.edu 0.35" };
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

//Testing the three types of deletions
TEST_CASE("Dead End", "[dead_end]") {

	AdjacencyList graph;
	graph.addTo("google.com", "gmail.com");
	graph.addTo("google.com", "maps.com");
	graph.addTo("facebook.com", "ufl.edu");
	graph.addTo("ufl.edu", "google.com");
	graph.addTo("ufl.edu", "gmail.com");
	graph.addTo("maps.com", "facebook.com");
	std::vector<string> actualOutput = graph.testOut(2);
	std::vector<string> expectedOutput = { "facebook.com 0.20", "gmail.com 0.20", "google.com 0.10", "maps.com 0.10", "ufl.edu 0.20" };
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

//Testing a large amount of inputs with Insert() and Remove()
TEST_CASE("Many Websites", "[websites]") {

	AdjacencyList graph;
	graph.addTo("google.com", "gmail.com");
	graph.addTo("google.com", "maps.com");
	graph.addTo("facebook.com", "ufl.edu");
	graph.addTo("ufl.edu", "google.com");
	graph.addTo("ufl.edu", "gmail.com");
	graph.addTo("maps.com", "facebook.com");
	graph.addTo("gmail.com", "maps.com");
	graph.addTo("yahoo.com", "google.com");
	graph.addTo("google.com", "youtube.com");
	graph.addTo("youtube.com", "ufl.edu");
	graph.addTo("facebook.com", "yahoo.com");
	graph.addTo("coolmathgames.com", "poptropica.com");
	graph.addTo("ixl.com", "coolmathgames.com");
	graph.addTo("maps.com", "poptropica.com");
	graph.addTo("google.com", "trevorjgross.com");
	graph.addTo("trevorjgross.com", "poptropica.com");
	graph.addTo("ufl.edu", "pons.de");
	graph.addTo("pons.de", "trevorjgross.com");
	graph.addTo("maclay.org", "ufl.edu");
	graph.addTo("trevorjgross.com", "maclay.org");
	graph.addTo("facebook.com", "maclay.org");
	graph.addTo("maps.com", "pons.de");
	graph.addTo("trevorjgross.com", "youtube.com");
	graph.addTo("gmail.com", "trevorjgross.com");
	graph.addTo("maclay.org", "gmail.com");
	graph.addTo("maclay.org", "ixl.com");
	graph.addTo("facebook.com", "youtube.com");
	graph.addTo("poptropica.com", "youtube.com");
	std::vector<string> actualOutput = graph.testOut(2);
	std::vector<string> expectedOutput = { "coolmathgames.com 0.08", "facebook.com 0.03", "gmail.com 0.07", "google.com 0.10", "ixl.com 0.03", "maclay.org 0.05", "maps.com 0.06", "pons.de 0.05", "poptropica.com 0.13", "trevorjgross.com 0.14", "ufl.edu 0.12", "yahoo.com 0.02", "youtube.com 0.14" };
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Many Powers", "[powers]") {

	AdjacencyList graph;
	graph.addTo("google.com", "gmail.com");
	graph.addTo("google.com", "maps.com");
	graph.addTo("facebook.com", "ufl.edu");
	graph.addTo("ufl.edu", "google.com");
	graph.addTo("ufl.edu", "gmail.com");
	graph.addTo("maps.com", "facebook.com");
	graph.addTo("gmail.com", "maps.com");
	std::vector<string> actualOutput = graph.testOut(25);
	std::vector<string> expectedOutput = { "facebook.com 0.25", "gmail.com 0.17", "google.com 0.11", "maps.com 0.22", "ufl.edu 0.25" };
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Many Websites and Many Powers", "[mega]") {

	AdjacencyList graph;
	graph.addTo("google.com", "gmail.com");
	graph.addTo("google.com", "maps.com");
	graph.addTo("facebook.com", "ufl.edu");
	graph.addTo("ufl.edu", "google.com");
	graph.addTo("ufl.edu", "gmail.com");
	graph.addTo("maps.com", "facebook.com");
	graph.addTo("gmail.com", "maps.com");
	graph.addTo("yahoo.com", "google.com");
	graph.addTo("google.com", "youtube.com");
	graph.addTo("youtube.com", "ufl.edu");
	graph.addTo("facebook.com", "yahoo.com");
	graph.addTo("coolmathgames.com", "poptropica.com");
	graph.addTo("ixl.com", "coolmathgames.com");
	graph.addTo("maps.com", "poptropica.com");
	graph.addTo("google.com", "trevorjgross.com");
	graph.addTo("trevorjgross.com", "poptropica.com");
	graph.addTo("ufl.edu", "pons.de");
	graph.addTo("pons.de", "trevorjgross.com");
	graph.addTo("maclay.org", "ufl.edu");
	graph.addTo("trevorjgross.com", "maclay.org");
	graph.addTo("facebook.com", "maclay.org");
	graph.addTo("maps.com", "pons.de");
	graph.addTo("trevorjgross.com", "youtube.com");
	graph.addTo("gmail.com", "trevorjgross.com");
	graph.addTo("maclay.org", "gmail.com");
	graph.addTo("maclay.org", "ixl.com");
	graph.addTo("facebook.com", "youtube.com");
	graph.addTo("poptropica.com", "youtube.com");
	std::vector<string> actualOutput = graph.testOut(10);
	std::vector<string> expectedOutput = { "coolmathgames.com 0.02", "facebook.com 0.02", "gmail.com 0.10", "google.com 0.07", "ixl.com 0.02", "maclay.org 0.05", "maps.com 0.07", "pons.de 0.09", "poptropica.com 0.09", "trevorjgross.com 0.15", "ufl.edu 0.18", "yahoo.com 0.01", "youtube.com 0.15" };
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}