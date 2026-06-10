// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1



/*
🔴 Union of Two Arrays (Using Map)

🧠 Idea:

- Use map where:
      key   = array element
      value = 1

- Insert all elements from both arrays into the map.

- Map automatically keeps keys sorted.

- Duplicate keys are stored only once.

------------------------------------------------------

Why value = 1?

- We only care whether an element exists.
- The value is just a placeholder.

------------------------------------------------------

⏱️ TC:

Insertion:
    O((N + M) log(N + M))

Traversal:
    O(N + M)

------------------------------------------------------

📦 SC:

    O(N + M)

------------------------------------------------------

🎯 One line:

"Use map keys to store unique elements and leverage map's sorted ordering."
*/
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        map<int, int> mp; 
        
        for(auto x : a)
        {
            if(mp[x] == 0)
            {
                mp[x] = 1;
            }
        } 
        for(auto x : b)
        {
            if(mp[x] == 0)
            {
                mp[x] = 1;
            }
        }
        
        vector<int> res; 
        
        for(auto x : mp)
        {
            if(x.second == 1)
                res.emplace_back(x.first);
        }
        
        return res;
    }
};

/*
🔴 Union of Two Arrays (Using Set)

🧠 Idea:

- A set automatically:
    1. Stores only unique elements
    2. Keeps elements in sorted order

- Insert all elements from both arrays into the set.

- Convert the set back into a vector.

------------------------------------------------------

Flow:

1. Insert all elements of a into set
2. Insert all elements of b into set
3. Traverse set and store elements in result vector

------------------------------------------------------

🧠 Why does this work?

- Duplicate insertions are ignored by set
- Elements are automatically maintained in sorted order

------------------------------------------------------

⏱️ TC:

Insert all elements:
    O((N + M) log(N + M))

Copy set to vector:
    O(N + M)

Overall:
    O((N + M) log(N + M))

------------------------------------------------------

📦 SC:

Set + Result Vector:
    O(N + M)

------------------------------------------------------

🎯 One line:

"Insert everything into a set, then copy the unique sorted elements into a vector."
*/
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int> s; 
        
        for(auto x : a)
        {
            s.insert(x);
        } 
        for(auto x : b)
        {
            s.insert(x);
        }
        
        vector<int> res; 
        
        for(auto x : s)
        {
            res.emplace_back(x);
        }
        
        return res;
    }
};


/*
🔴 Union of Two Sorted Arrays

🧠 Idea:

- Use two pointers:
      first  -> array a
      second -> array b

- Since both arrays are sorted,
  the smaller element must appear next in the union.

------------------------------------------------------

At every step:

1. If a[first] < b[second]
      process a[first]
      move first

2. If a[first] > b[second]
      process b[second]
      move second

3. If equal
      process either one
      move both pointers

------------------------------------------------------

🧠 Duplicate Handling:

Before inserting:

    res.empty() || currentElement > res.back()

This ensures:

- No duplicate values are inserted
- Every value appears only once in union

------------------------------------------------------

Why does this work?

Because arrays are sorted.

So if a value is equal to res.back(),
it has already been added before.

------------------------------------------------------

After one array finishes:

- Process remaining elements
- Still check for duplicates before inserting

------------------------------------------------------

⏱️ TC: O(N + M)

📦 SC: O(N + M)

------------------------------------------------------

🎯 One line:

"Merge two sorted arrays while skipping duplicates."
*/
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int first = 0; 
        int second =0 ;
        vector<int> res;
        while(first < a.size() && second < b.size())
        {
           
            if(a[first] < b[second])
            {
                if(res.size() == 0 || a[first] > res.back())
                    res.emplace_back(a[first]);
                first++;
            }
            else if(a[first] > b[second])
            {
                if(res.size() == 0 || b[second] > res.back())
                    res.emplace_back(b[second]);
                second++;
            }
            else
            {
                if(res.size() == 0 || a[first] > res.back())
                    res.emplace_back(a[first]);
                first++;
                second++;
            }
            
        }
        
        
        while(first < a.size())
        {
            if(res.size() == 0 || res.back() < a[first])
            {
                res.emplace_back(a[first]);
            }
            first++;
            
        } 
        while(second < b.size())
        {
            if(res.size() == 0 || res.back() < b[second])
            {
                res.emplace_back(b[second]);
            }
            second++;
        }
        
        return res;
    }
};