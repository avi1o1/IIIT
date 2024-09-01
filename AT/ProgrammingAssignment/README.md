# Submission Report

## Question 1
- The solution is based on the depth-first search (DFS) principle.
- We maintain a `cnt` array and traverse through the DFA, updating values for each vertex.
- After `M` transitions, we stop and return the `cnt` array.

**Note**: The solution assumes a maximum out-degree of 1 for any vertex. If the out-degree is greater than 1, there could be multiple possible outputs, and the code would return one of these.

## Question 2
- The JavaScript library `lindenmayer` is used for this question. Each part has an associated JavaScript file, which can be integrated with the provided `index.html` to produce the required output. All these files are located in the `code` folder.
- Most of the required functionalities are provided by the library itself. We just need to specify the axioms, grammar, etc., to achieve the desired result.
- Additionally, I have included some cosmetic enhancements, such as delays between each iteration (for better understanding of the formation), slight CSS (for a visually pleasing look), and other minor improvements.

**Note**: I am comparing my results with [this online L-system generator](http://piratefsh.github.io/p5js-art/public/lsystems/). For the context-sensitive grammar (4th part), giving it less precedence (as per the order in question) matches the results. However, giving it higher precedence (as per Wikipedia definition) yields differences. After dry running both approaches, I concluded the online generator is incorrect. Thus, I assumed less precedence for context-sensitive grammar, which matches the expected results.

## Question 3
- We can analyze the differences between the given graphics, which are just one iteration apart, to identify the variable and terminal strokes.
- This analysis provides a rough idea of the `grammar` and `angles` in use. With some trial and error using an L-System generator (like the one created in Question 2), we can determine the exact parameters.
- Finally, we can apply the inverse grammar on variable strokes to reach iteration 0 and obtain the `axiom`.

---

---

---