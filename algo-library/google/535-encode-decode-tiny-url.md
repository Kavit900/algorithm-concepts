## Problem Statement

TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

## Questions to Ask

1. What is the character set that could be present in the url, like just numbers and letters or other special characters are possible as well ? Use numbers `0 to 9` 

2. What should be the size of encoded string? in our case it's 6. 

## Approach

1. 