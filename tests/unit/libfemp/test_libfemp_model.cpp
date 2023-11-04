
#include <gtest/gtest.h>

#include <libfemp/Model.hpp>

namespace {

TEST(libfemp_model, Given_InitializedModel_When_NoElementWasAdded_Then_NumberOfElementsIsZero) {
	// Given
	fem::Model m;

	// When

	// Then
	EXPECT_EQ(m.numberOfElements(), 0);
}

TEST(libfemp_model, Given_InitializedModel_When_GetElementList_Then_ElementListSizeIsZero) {
	// Given
	fem::Model m;

	// When
	auto elements = m.getElementList();

	// Then
	EXPECT_EQ(elements.size(), 0);
}

TEST(libfemp_model, Given_InitializedModel_When_GetLoadPatternList_Then_LoadPatternListSizeIsZero) {
	// Given
	fem::Model m;

	// When
	auto loadPatterns = m.getLoadPatternList();

	// Then
	EXPECT_EQ(loadPatterns.size(), 0);
}

TEST(libfemp_model, Given_InitializedModel_When_GetElementGroups_Then_ElementGroupsSizeIsZero) {
	// Given
	fem::Model m;

	// When
	auto elementGroups = m.getElementGroups();

	// Then
	EXPECT_EQ(elementGroups.size(), 0);
}

TEST(libfemp_model, Given_InitializedModel_When_GetNodeGroups_Then_NodeGroupsSizeIsZero) {
	// Given
	fem::Model m;

	// When
	auto nodeGroups = m.getNodeGroups();

	// Then
	EXPECT_EQ(nodeGroups.size(), 0);
}

}  // namespace

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
