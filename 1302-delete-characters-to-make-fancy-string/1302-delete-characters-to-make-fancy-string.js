/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function(s) {
    let result = [];

    for (let i = 0; i < s.length; i++) {
        let len = result.length;
   
    if (len >=2 && result[len - 1] == s[i] && result[len - 2] == s[i]){
        continue;
    }
    result.push(s[i]);
     }
     return result.join('');
};