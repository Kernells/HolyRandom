# HolyRandom

<img width="1536" height="1024" alt="HolyRandom" src="img/HolyRandom.png" />

HolyRandom is a web-powered randomness engine that generates unpredictable numbers by crawling different websites,
And converting their characters into numbers which are fed into a random number generator to decide
to add it or substract it.

## Why It's Different

Most random number generators are deterministic and preditactable under the hood.
HolyRandom introduces environmental unpredictability into the generation process.

## Configuration

Inside the header file, there will be a couple of configuration settings for you to arrange

- COUNT_NEGATIVE_AS_DIGIT. This configuration determines if at the moment of creating a negative number, The number will be exactly the same size input or will be one digit more because the negative symbol.
- ALLOW_NEGATIVES. This configuration determines if the randomly generated numbers can be negatives.
- ALLOW_POSITIVES. This configuration determines if the randomly generated numbers can be positives.

## Usage

HolyRandom provides two main functions. getHolyRandom and getHolyRandom_S.
These two functions take as single parameter the size of the randomly generated number and return the random number.

- getHolyRandom which returns an int which max size is 10.
- getHolyRandom_S which returns an string which has no max size.

## Examples

```cpp

#include <HolyRandom.h>

std::string HolyRandom_S = HolyRandom::getHolyRandom_S(20);

int HolyRandom = HolyRandom::getHolyRandom(10);

```

# Made by Kernels.
