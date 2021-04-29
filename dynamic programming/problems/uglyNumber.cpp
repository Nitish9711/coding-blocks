// You are provided a sequence of number. All numbers of that sequence is in increasing order (including 1) and whose only prime factors are 2, 3 or 5 (except 1). You need to find the nth number of that sequence.

// Dynamic Programming can be applied to this if we can formulate Ugly(n) in terms of Ugly(k) where k < n

// If we have k ugly numbers already, then the k+1 ugly number has to be some multiple of the previous ugly numbers only else it would not remain ugly.

// We need to multiply previous ugly numbers by 2,3 and 5 and choose the next highest.

// But if we multiply all the previous numbers by 2,3 and 5 then it will become thrice O(n2) operations to find all such multiples and then another O(n) operations to find the minimum among them.

// To optimize, we will keep track where last multiple of each (2,3,5) was kept.

// If we know that, then we need not consider ugly numbers previous to those.

