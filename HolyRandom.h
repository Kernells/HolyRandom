#pragma once

#include <iostream>
#include <string>

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "Dependencies/httplib/httplib.h"

// HolyRandom by Kernels.

// Configuration

#define VERSION 1.0

#define COUNT_NEGATIVE_AS_DIGIT true
#define ALLOW_NEGATIVES true
#define ALLOW_POSITIVES true

std::vector<std::string> Websites = 
{
	"google.com",
	"youtube.com"
}; // Adding more will help produce a more random number


namespace HolyRandom {

	std::string getHolyRandom_S(int Size) {
		int Result = 0;
		std::string StringResult;
		std::string ResultStack;

		std::string StringedResult = std::to_string(Result);
		StringedResult.erase(
			std::remove(StringedResult.begin(), StringedResult.end(), '-'),
			StringedResult.end()
		);
		while ((ResultStack).length() < Size) {
			ResultStack += std::to_string(Result);
			ResultStack.erase(
				std::remove(ResultStack.begin(), ResultStack.end(), '-'),
				ResultStack.end()
			);
			Result = 0;
			StringedResult = std::to_string(Result);
			StringedResult.erase(
				std::remove(StringedResult.begin(), StringedResult.end(), '-'),
				StringedResult.end());
			for (std::string Website : Websites) {
				httplib::SSLClient cli(Website, 443);
				cli.set_follow_location(true);
				auto res = cli.Get("/");
				res->status;
				res->body;

				for (char c : res->body) {

					std::random_device rd2;
					std::mt19937 engine2(rd2());
					std::uniform_int_distribution<int> distribution2(0, 1);
					int random_num2 = distribution2(engine2);

					std::random_device rd;
					std::mt19937 engine(rd());
					std::uniform_int_distribution<int> distribution(0, 2);
					int random_num = distribution(engine);

					int val = c - 'a' + 1;

					if (random_num2 == 0) {
						val = std::abs(val);
					}

					switch (random_num) {
					case 0:
						Result -= val;
						break;
					case 1:
						Result += val;
						break;
					case 2:
						Result *= val;
						break;
					}
				}
			}
		}

		bool IsNegative = (std::to_string(Result).find("-") != std::string::npos);

		StringResult = std::to_string(Result) + ResultStack;

		StringedResult = StringResult;
		StringedResult.erase(
			std::remove(StringedResult.begin(), StringedResult.end(), '-'),
			StringedResult.end()
		);
		if (StringedResult.length() > Size) {
			std::string FixedResult = "";
			for (int i = 0; i < Size; i++) {
				FixedResult += StringedResult[i];
			}

			if ((IsNegative && ALLOW_NEGATIVES) || !ALLOW_POSITIVES) {

				FixedResult = "-" + FixedResult;

				if (COUNT_NEGATIVE_AS_DIGIT) {
					FixedResult.pop_back();
				}
			}
			return FixedResult;
		}
		return std::to_string(Result);
	}

	int getHolyRandom(int Size) {

		if (Size >= 11) { // Out of range guard
			std::cout << "getHolyRandom size can't exceed 11.For longer random numbers use getHolyRandom_S.";
			return -1;
		}

		int Result = 0;
		std::string StringResult;
		std::string ResultStack;

		std::string StringedResult = std::to_string(Result);
		StringedResult.erase(
			std::remove(StringedResult.begin(), StringedResult.end(), '-'),
			StringedResult.end()
		);
		while ((ResultStack).length() < Size) {
			ResultStack += std::to_string(Result);
			ResultStack.erase(
				std::remove(ResultStack.begin(), ResultStack.end(), '-'),
				ResultStack.end()
			);
			Result = 0;
			StringedResult = std::to_string(Result);
			StringedResult.erase(
				std::remove(StringedResult.begin(), StringedResult.end(), '-'),
				StringedResult.end());
			for (std::string Website : Websites) {
				httplib::SSLClient cli(Website, 443);
				cli.set_follow_location(true);
				auto res = cli.Get("/");
				res->status;
				res->body;

				for (char c : res->body) {

					std::random_device rd2;
					std::mt19937 engine2(rd2());
					std::uniform_int_distribution<int> distribution2(0, 1);
					int random_num2 = distribution2(engine2);

					std::random_device rd;
					std::mt19937 engine(rd());
					std::uniform_int_distribution<int> distribution(0, 2);
					int random_num = distribution(engine);

					int val = c - 'a' + 1;

					if (random_num2 == 0) {
						val = std::abs(val);
					}

					switch (random_num) {
					case 0:
						Result -= val;
						break;
					case 1:
						Result += val;
						break;
					case 2:
						Result *= val;
						break;
					}
				}
			}
		}

		bool IsNegative = (std::to_string(Result).find("-") != std::string::npos);

		StringResult = std::to_string(Result) + ResultStack;

		StringedResult = StringResult;
		StringedResult.erase(
			std::remove(StringedResult.begin(), StringedResult.end(), '-'),
			StringedResult.end()
		);
		if (StringedResult.length() > Size) {
			std::string FixedResult = "";
			for (int i = 0; i < Size; i++) {
				FixedResult += StringedResult[i];
			}
			
			if ((IsNegative && ALLOW_NEGATIVES) || !ALLOW_POSITIVES) {

				FixedResult = "-" + FixedResult;

				if (COUNT_NEGATIVE_AS_DIGIT) {
					FixedResult.pop_back();
				}
			}
			return std::stoi(FixedResult);
		}
		return Result;
	}

}