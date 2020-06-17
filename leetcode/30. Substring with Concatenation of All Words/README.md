#### 30. Substring with Concatenation of All Words

> You are given a string, **s**, and a list of words, **words**, that are all of the same length. Find all starting indices of substring(s) in **s** that is a concatenation of each word in **words** exactly once and without any intervening characters.
>
>  
>
> **Example 1:**
>
> ```
> Input:
>   s = "barfoothefoobarman",
>   words = ["foo","bar"]
> Output: [0,9]
> Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
> The output order does not matter, returning [9,0] is fine too.
> ```
>
> **Example 2:**
>
> ```c
> Input:
>   s = "wordgoodgoodgoodbestword",
>   words = ["word","good","best","word"]
> Output: []
> ```
>
> 

Since all words are all of the same length, so we can regard them as "nodes".

there for, we can transform it into a simple sliding window problem.

​	firstly ,we have :

​		origin_times : store map of {word -> time_can_appear}

​		times : store map of current words in our windows and their time_appears.

- if we encounter a word that dont exist in words list, then this windows should be abandoned.
- otherwise, we check if we have "appear time" left enough for this new word to add in our word list.
  - if we dont have, then we should shrink left window from left side, until we have room for the new word.
  - now we have room ,just add the new word into our word list.
- check if we have enough words in our window, if so ,record the ans.

