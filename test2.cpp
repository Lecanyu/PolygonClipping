///*
//* An implementation of "Efficient clipping of arbitrary polygons" See http://www.inf.usi.ch/hormann/papers/Greiner.1998.ECO.pdf
//* It is based on Jordan curve theorem https://people.math.osu.edu/fiedorowicz.1/math655/Jordan.html
//* Including intersection, union and difference
//* -----------------------------------------------------
//* Here is an inside example
//*/

#include "PolyUtils.h"
#include "PolygonClipping.h"
#include <iostream>


int main()
{
	std::vector<PolyClip::Point2d> vertices1;
	vertices1.push_back(PolyClip::Point2d(10.0, 10.0));
	vertices1.push_back(PolyClip::Point2d(10.0, 100.0));
	vertices1.push_back(PolyClip::Point2d(100.0, 100.0));
	vertices1.push_back(PolyClip::Point2d(100.0, 10.0));
	PolyClip::Polygon polygon1(vertices1);

	std::vector<PolyClip::Point2d> vertices2;
	vertices2.push_back(PolyClip::Point2d(20, 20.0));
	vertices2.push_back(PolyClip::Point2d(20, 80.0));
	vertices2.push_back(PolyClip::Point2d(80, 80.0));
	PolyClip::Polygon polygon2(vertices2);


	std::cout << "#################### Intersection #####################\n";
	PolyClip::PloygonOpration::DetectIntersection(polygon1, polygon2);
	std::vector<std::vector<PolyClip::Point2d>> possible_result;
	if (PolyClip::PloygonOpration::Mark(polygon1, polygon2, possible_result, PolyClip::MarkIntersection))
	{
		std::vector<std::vector<PolyClip::Point2d>> results = PolyClip::PloygonOpration::ExtractIntersectionResults(polygon1);
		for (int i = 0; i<results.size(); ++i)
		{
			for (auto p : results[i])
				std::cout << "(" << p.x_ << ", " << p.y_ << ")" << "---";
			std::cout << "\n";
		}
	}
	else
	{
		if (possible_result.size() == 0)
			std::cout << "No intersection\n";
		else
		{
			for (int i = 0; i<possible_result.size(); ++i)
			{
				for (auto p : possible_result[i])
					std::cout << "(" << p.x_ << ", " << p.y_ << ")" << "---";
				std::cout << "\n";
			}
		}
	}

	std::cout << "\n#################### Union #####################\n";
	possible_result.clear();
	PolyClip::Polygon poly1(vertices1);
//	= polygon1;
	PolyClip::Polygon poly2(vertices2);
//	= polygon2;
	PolyClip::PloygonOpration::DetectIntersection(poly1, poly2);
	if (PolyClip::PloygonOpration::Mark(poly1, poly2, possible_result, PolyClip::MarkUnion))
	{
		std::vector<std::vector<PolyClip::Point2d>> results = PolyClip::PloygonOpration::ExtractUnionResults(poly1);
		for (int i = 0; i<results.size(); ++i)
		{
			for (auto p : results[i])
				std::cout << "(" << p.x_ << ", " << p.y_ << ")" << "---";
			std::cout << "\n";
		}
	}
	else
	{
		if (possible_result.size() == 0)
			std::cout << "No intersection\n";
		else
		{
			for (int i = 0; i<possible_result.size(); ++i)
			{
				for (auto p : possible_result[i])
					std::cout << "(" << p.x_ << ", " << p.y_ << ")" << "---";
				std::cout << "\n";
			}
		}
	}

	std::cout << "\n#################### Differentiate #####################\n";
	possible_result.clear();
	PolyClip::Polygon pol1(vertices1);
//	= polygon1;
	PolyClip::Polygon pol2(vertices2);
//	= polygon2;
	PolyClip::PloygonOpration::DetectIntersection(pol1, pol2);
	if (PolyClip::PloygonOpration::Mark(pol1, pol2, possible_result, PolyClip::MarkDifferentiate))
	{
		std::vector<std::vector<PolyClip::Point2d>> results = PolyClip::PloygonOpration::ExtractDifferentiateResults(pol1);
		for (int i = 0; i<results.size(); ++i)
		{
			for (auto p : results[i])
				std::cout << "(" << p.x_ << ", " << p.y_ << ")" << "---";
			std::cout << "\n";
		}
	}
	else
	{
		if (possible_result.size() == 0)
			std::cout << "No intersection\n";
		else
		{
			for (int i = 0; i<possible_result.size(); ++i)
			{
				for (auto p : possible_result[i])
					std::cout << "(" << p.x_ << ", " << p.y_ << ")" << "---";
				std::cout << "\n";
			}
		}
	}

	return 0;
}