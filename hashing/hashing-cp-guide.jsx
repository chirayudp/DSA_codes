import { useState } from "react";

const hashingData = {
  patterns: [
    {
      id: "freq_map",
      title: "Frequency Map",
      icon: "📊",
      difficulty: "800–1200",
      color: "#00ff88",
      intuition: "Whenever you see 'count occurrences', 'find duplicates', 'most frequent', or 'two elements equal' — reach for a frequency map. You're trading O(n²) brute force for O(n) by caching counts.",
      when: [
        "Count how many times each value appears",
        "Check if two arrays have the same elements",
        "Find the first duplicate",
        "Group elements by value"
      ],
      template: `// Frequency Map Template
unordered_map<int, int> freq;

for (int x : arr) freq[x]++;

// Check if x exists with count >= k
if (freq[x] >= k) { ... }

// Iterate sorted (use map instead)
map<int, int> sorted_freq;
for (auto& [val, cnt] : sorted_freq) { ... }`,
      problems: [
        {
          name: "Codeforces 1A – Theatre Square",
          rating: "1000",
          link: "https://codeforces.com/problemset/problem/1/A",
          explanation: "Not hashing, but teaches map basics — used as warm-up."
        },
        {
          name: "CF 546D – Soldier and Number Game",
          rating: "1700",
          link: "https://codeforces.com/problemset/problem/546/D",
          explanation: "Precompute smallest prime factor with sieve, then hash frequency of prime factors. Classic freq map after factorization."
        },
        {
          name: "CF 1690C – Restoring the Duration of Tasks",
          rating: "900",
          link: "https://codeforces.com/problemset/problem/1690/C",
          explanation: "Simple greedy but teaches you to track 'last seen' values — a form of hash-based state tracking."
        }
      ]
    },
    {
      id: "set_membership",
      title: "Set Membership / Existence Check",
      icon: "🔍",
      difficulty: "900–1400",
      color: "#00aaff",
      intuition: "When the question is 'does X exist?' or 'have I seen this before?', a hash set gives you O(1) lookup. The key insight: you don't need the count, just presence/absence.",
      when: [
        "Check if a complement exists (two-sum style)",
        "Find elements in one array but not another",
        "Detect cycles or revisited states",
        "Avoid processing the same element twice"
      ],
      template: `// Set Membership Template
unordered_set<int> seen;

for (int x : arr) {
    int complement = target - x;
    if (seen.count(complement)) {
        // found pair!
    }
    seen.insert(x);
}

// Two-array intersection
unordered_set<int> setA(a.begin(), a.end());
for (int x : b) {
    if (setA.count(x)) { /* x in both */ }
}`,
      problems: [
        {
          name: "CF 4C – Registration System",
          rating: "1300",
          link: "https://codeforces.com/problemset/problem/4/C",
          explanation: "Direct application: use a map to track if a name was seen before and count duplicates. Classic 'first occurrence vs duplicates' pattern."
        },
        {
          name: "CF 1722E – Misha and Paintings",
          rating: "1800",
          link: "https://codeforces.com/problemset/problem/1722/E",
          explanation: "Use a set of 'active' colors in a sliding window on 2D grid. Checks existence of color frequency changes."
        },
        {
          name: "CF 1520C – Not Adjacent Matrix",
          rating: "1200",
          link: "https://codeforces.com/problemset/problem/1520/C",
          explanation: "Needs tracking of used values. Set lets you efficiently find the next available element."
        }
      ]
    },
    {
      id: "prefix_hash",
      title: "Prefix Sum + Hashing",
      icon: "➕",
      difficulty: "1300–2000",
      color: "#ff6b35",
      intuition: "Combine prefix sums with a hash map. The core trick: if prefix[j] - prefix[i] = target, then subarray [i+1..j] has sum = target. Store prefix sums in a map to find matching pairs in O(n).",
      when: [
        "Count subarrays with sum = k",
        "Find subarray with sum divisible by k (store prefix mod k)",
        "Longest subarray with equal 0s and 1s",
        "Number of subarrays with XOR = k"
      ],
      template: `// Prefix Sum + Hash Map Template
// Count subarrays with sum == k
unordered_map<long long, int> prefix_count;
prefix_count[0] = 1;  // empty prefix
long long prefix = 0;
int ans = 0;

for (int x : arr) {
    prefix += x;
    // We need prefix - k to have appeared before
    ans += prefix_count[prefix - k];
    prefix_count[prefix]++;
}

// XOR variant: replace + with ^
// Mod variant: prefix %= mod before storing`,
      problems: [
        {
          name: "CF 1398C – Good Subarrays",
          rating: "1500",
          link: "https://codeforces.com/problemset/problem/1398/C",
          explanation: "Count pairs (i,j) where subarray is 'good'. Store prefix info in a map. Directly uses the prefix+hash pattern."
        },
        {
          name: "CF 1073E – Segment Sum",
          rating: "2100",
          link: "https://codeforces.com/problemset/problem/1073/E",
          explanation: "Digit DP + hashing. Harder variant where you hash digit masks for memoization."
        },
        {
          name: "CF 835C – Bob's Game",
          rating: "1900",
          link: "https://codeforces.com/problemset/problem/835/C",
          explanation: "Prefix XOR with map to count subarrays with XOR = 0. Pure prefix hash pattern."
        }
      ]
    },
    {
      id: "string_hash",
      title: "Polynomial String Hashing",
      icon: "🔤",
      difficulty: "1600–2400",
      color: "#c084fc",
      intuition: "Treat a string as a polynomial: hash(s) = s[0]*p^0 + s[1]*p^1 + ... mod M. This lets you compare any substring in O(1) after O(n) preprocessing. The insight: string comparison becomes integer comparison.",
      when: [
        "Find repeated substrings",
        "Check if two substrings are equal in O(1)",
        "Binary search on answer involving string patterns",
        "Count distinct substrings"
      ],
      template: `// Polynomial Rolling Hash Template
const long long MOD = 1e9 + 7, BASE = 131;

vector<long long> h(n+1, 0), pw(n+1, 1);

for (int i = 0; i < n; i++) {
    h[i+1] = (h[i] * BASE + s[i]) % MOD;
    pw[i+1] = pw[i] * BASE % MOD;
}

// Hash of substring s[l..r] (0-indexed)
auto getHash = [&](int l, int r) {
    return (h[r+1] - h[l] * pw[r-l+1] % MOD + MOD * 2) % MOD;
};

// Use DOUBLE HASHING to reduce collision probability
// Two different (BASE, MOD) pairs simultaneously`,
      problems: [
        {
          name: "CF 126E – Palindrome",
          rating: "2000",
          link: "https://codeforces.com/problemset/problem/126/E",
          explanation: "Use string hashing + binary search to find longest palindromic substring. Classic binary search on hash."
        },
        {
          name: "CF 271D – Good Substrings",
          rating: "1700",
          link: "https://codeforces.com/problemset/problem/271/D",
          explanation: "Count distinct 'good' substrings. Store all substring hashes in a set. Directly tests polynomial hashing."
        },
        {
          name: "CF 1063F – String Journey",
          rating: "2700",
          link: "https://codeforces.com/problemset/problem/1063/F",
          explanation: "Hard: binary search + Z-function or hashing to verify substring conditions. Shows hashing enabling binary search on strings."
        }
      ]
    },
    {
      id: "map_compression",
      title: "Coordinate Compression via Map",
      icon: "🗜️",
      difficulty: "1200–1800",
      color: "#fbbf24",
      intuition: "When values are huge (up to 10^9) but there are few of them (≤10^5), map them to small indices. A sorted map or rank array compresses the 'coordinate space' so you can use arrays/segment trees efficiently.",
      when: [
        "Values are large but count is small",
        "Need to use a BIT/segment tree on values",
        "Count inversions with large values",
        "Range queries on compressed coordinates"
      ],
      template: `// Coordinate Compression Template
vector<int> vals = arr; // copy
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());

// Compress: get rank of x
auto compress = [&](int x) {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
};

// Now arr[i] compressed to [0, vals.size())
vector<int> comp_arr;
for (int x : arr) comp_arr.push_back(compress(x));

// Alternative: use map<int,int> for online compression
map<int,int> rank_map;
int cnt = 0;
for (int x : arr) {
    if (!rank_map.count(x)) rank_map[x] = cnt++;
}`,
      problems: [
        {
          name: "CF 61E – Enemy Is a Tree",
          rating: "2000",
          link: "https://codeforces.com/problemset/problem/61/E",
          explanation: "Compress values then use a BIT. Classic example of compression enabling an otherwise impossible solution."
        },
        {
          name: "CF 459C – Pashmak and Buses",
          rating: "1700",
          link: "https://codeforces.com/problemset/problem/459/C",
          explanation: "Enumerate sequences in lexicographic order. Compression of states via map is key."
        },
        {
          name: "CF 785C – Anton and Tree",
          rating: "1900",
          link: "https://codeforces.com/problemset/problem/785/C",
          explanation: "Compress black/white layers into a smaller structure using BFS + set operations."
        }
      ]
    },
    {
      id: "multiset_sliding",
      title: "Multiset / Sliding Window Hash",
      icon: "🪟",
      difficulty: "1400–2000",
      color: "#f472b6",
      intuition: "For sliding window problems where you need to track sorted order or count within a window, a multiset or frequency map + pointer gives O(n log n). The trick: inserting and removing from a sorted structure as the window moves.",
      when: [
        "Minimum/maximum in every window of size k",
        "Median in a sliding window",
        "Count of distinct elements in window",
        "Check if window matches a pattern"
      ],
      template: `// Sliding Window with Map/Multiset
// Count distinct elements in each window of size k
unordered_map<int, int> window;
int distinct = 0;

// Init first window
for (int i = 0; i < k; i++) {
    if (window[arr[i]]++ == 0) distinct++;
}
// ans for window [0, k-1]

for (int i = k; i < n; i++) {
    // Add right element
    if (window[arr[i]]++ == 0) distinct++;
    // Remove left element
    if (--window[arr[i-k]] == 0) distinct--;
    // ans for window [i-k+1, i]
}

// For sorted access, use multiset<int> instead`,
      problems: [
        {
          name: "CF 1208F – Bits And Pieces",
          rating: "2300",
          link: "https://codeforces.com/problemset/problem/1208/F",
          explanation: "Sliding window with bitmask hash. Track which bits are available in windows of increasing size."
        },
        {
          name: "CF 1446C – Xor Tree",
          rating: "1800",
          link: "https://codeforces.com/problemset/problem/1446/C",
          explanation: "Trie + set operations. Teach you to think about set intersections over ranges."
        },
        {
          name: "CF 1077C – Good Array",
          rating: "1600",
          link: "https://codeforces.com/problemset/problem/1077/C",
          explanation: "Frequency map in a sliding window to check 'good' condition efficiently."
        }
      ]
    }
  ],
  intuitionSteps: [
    { step: "1", text: "See 'duplicates', 'count', 'frequency' → Frequency Map" },
    { step: "2", text: "See 'exists', 'seen before', 'complement' → Hash Set" },
    { step: "3", text: "See 'subarray sum = k', 'divisible' → Prefix + Hash" },
    { step: "4", text: "See 'substring comparison', 'repeated pattern' → String Hash" },
    { step: "5", text: "See values up to 10^9 with small count → Coordinate Compress" },
    { step: "6", text: "See 'window of size k' + 'distinct/median' → Sliding Window Map" }
  ]
};

export default function HashingGuide() {
  const [activePattern, setActivePattern] = useState(0);
  const [activeTab, setActiveTab] = useState("intuition");
  const [copiedIdx, setCopiedIdx] = useState(null);

  const pattern = hashingData.patterns[activePattern];

  const copyCode = (code, idx) => {
    navigator.clipboard.writeText(code);
    setCopiedIdx(idx);
    setTimeout(() => setCopiedIdx(null), 1500);
  };

  return (
    <div style={{
      background: "#0a0a0f",
      minHeight: "100vh",
      fontFamily: "'JetBrains Mono', 'Fira Code', monospace",
      color: "#e2e8f0",
      padding: "0"
    }}>
      {/* Header */}
      <div style={{
        background: "linear-gradient(135deg, #0f0f1a 0%, #1a0f2e 100%)",
        borderBottom: "1px solid #1e1e3f",
        padding: "28px 32px 20px",
        position: "sticky",
        top: 0,
        zIndex: 100,
        backdropFilter: "blur(12px)"
      }}>
        <div style={{ maxWidth: 1100, margin: "0 auto" }}>
          <div style={{ display: "flex", alignItems: "center", gap: 12, marginBottom: 4 }}>
            <span style={{ fontSize: 22 }}>⚡</span>
            <h1 style={{ margin: 0, fontSize: 20, fontWeight: 700, color: "#fff", letterSpacing: "-0.02em" }}>
              Hashing Patterns for Competitive Programming
            </h1>
            <span style={{
              background: "#1a1a3e",
              border: "1px solid #3730a3",
              color: "#818cf8",
              fontSize: 10,
              padding: "2px 8px",
              borderRadius: 20,
              fontWeight: 600,
              letterSpacing: "0.05em"
            }}>CODEFORCES</span>
          </div>
          <p style={{ margin: 0, color: "#64748b", fontSize: 12 }}>
            6 core patterns · Real CF problems · Templates you can copy-paste
          </p>

          {/* Intuition Quick Guide */}
          <div style={{
            marginTop: 16,
            display: "flex",
            gap: 8,
            flexWrap: "wrap"
          }}>
            {hashingData.intuitionSteps.map((s, i) => (
              <div key={i} onClick={() => setActivePattern(i)} style={{
                background: activePattern === i ? "#1e1b4b" : "#111128",
                border: `1px solid ${activePattern === i ? "#6366f1" : "#1e1e3f"}`,
                borderRadius: 6,
                padding: "4px 10px",
                fontSize: 10,
                color: activePattern === i ? "#a5b4fc" : "#475569",
                cursor: "pointer",
                transition: "all 0.15s",
                fontFamily: "inherit"
              }}>
                <span style={{ color: "#6366f1", fontWeight: 700 }}>{s.step}.</span> {s.text}
              </div>
            ))}
          </div>
        </div>
      </div>

      <div style={{ maxWidth: 1100, margin: "0 auto", padding: "24px 32px", display: "flex", gap: 20 }}>
        {/* Left Sidebar — Pattern List */}
        <div style={{ width: 220, flexShrink: 0 }}>
          <div style={{ fontSize: 10, color: "#475569", letterSpacing: "0.1em", fontWeight: 600, marginBottom: 10 }}>
            PATTERNS
          </div>
          {hashingData.patterns.map((p, i) => (
            <div
              key={p.id}
              onClick={() => { setActivePattern(i); setActiveTab("intuition"); }}
              style={{
                padding: "10px 12px",
                marginBottom: 4,
                borderRadius: 8,
                cursor: "pointer",
                background: activePattern === i ? "#111128" : "transparent",
                border: `1px solid ${activePattern === i ? p.color + "44" : "transparent"}`,
                transition: "all 0.15s",
              }}
            >
              <div style={{ display: "flex", alignItems: "center", gap: 8 }}>
                <span style={{ fontSize: 16 }}>{p.icon}</span>
                <div>
                  <div style={{
                    fontSize: 12,
                    fontWeight: 600,
                    color: activePattern === i ? p.color : "#94a3b8",
                    lineHeight: 1.3
                  }}>{p.title}</div>
                  <div style={{ fontSize: 10, color: "#475569", marginTop: 2 }}>
                    CF {p.difficulty}
                  </div>
                </div>
              </div>
            </div>
          ))}
        </div>

        {/* Main Content */}
        <div style={{ flex: 1, minWidth: 0 }}>
          {/* Pattern Header */}
          <div style={{
            background: "#0d0d1a",
            border: `1px solid ${pattern.color}33`,
            borderRadius: 12,
            padding: "20px 24px",
            marginBottom: 16,
            position: "relative",
            overflow: "hidden"
          }}>
            <div style={{
              position: "absolute", top: -40, right: -40,
              width: 120, height: 120,
              background: `radial-gradient(circle, ${pattern.color}15, transparent 70%)`,
              borderRadius: "50%"
            }} />
            <div style={{ display: "flex", alignItems: "center", gap: 12, marginBottom: 8 }}>
              <span style={{ fontSize: 28 }}>{pattern.icon}</span>
              <div>
                <h2 style={{ margin: 0, fontSize: 18, fontWeight: 700, color: "#fff" }}>
                  {pattern.title}
                </h2>
                <span style={{
                  fontSize: 11,
                  color: pattern.color,
                  background: pattern.color + "15",
                  padding: "1px 8px",
                  borderRadius: 20,
                  border: `1px solid ${pattern.color}33`
                }}>
                  CF Rating: {pattern.difficulty}
                </span>
              </div>
            </div>
          </div>

          {/* Tabs */}
          <div style={{ display: "flex", gap: 4, marginBottom: 16 }}>
            {["intuition", "template", "problems"].map(tab => (
              <button
                key={tab}
                onClick={() => setActiveTab(tab)}
                style={{
                  padding: "7px 16px",
                  borderRadius: 6,
                  border: `1px solid ${activeTab === tab ? pattern.color + "66" : "#1e1e3f"}`,
                  background: activeTab === tab ? pattern.color + "15" : "#0d0d1a",
                  color: activeTab === tab ? pattern.color : "#475569",
                  fontSize: 12,
                  fontWeight: 600,
                  cursor: "pointer",
                  fontFamily: "inherit",
                  letterSpacing: "0.03em",
                  transition: "all 0.15s"
                }}
              >
                {tab.charAt(0).toUpperCase() + tab.slice(1)}
              </button>
            ))}
          </div>

          {/* Tab Content */}
          {activeTab === "intuition" && (
            <div>
              <div style={{
                background: "#0d0d1a",
                border: "1px solid #1e1e3f",
                borderLeft: `3px solid ${pattern.color}`,
                borderRadius: "0 8px 8px 0",
                padding: "16px 20px",
                marginBottom: 16
              }}>
                <div style={{ fontSize: 10, color: pattern.color, fontWeight: 700, letterSpacing: "0.1em", marginBottom: 8 }}>
                  💡 THE INTUITION
                </div>
                <p style={{ margin: 0, fontSize: 13, lineHeight: 1.7, color: "#cbd5e1" }}>
                  {pattern.intuition}
                </p>
              </div>

              <div style={{
                background: "#0d0d1a",
                border: "1px solid #1e1e3f",
                borderRadius: 8,
                padding: "16px 20px"
              }}>
                <div style={{ fontSize: 10, color: "#64748b", fontWeight: 700, letterSpacing: "0.1em", marginBottom: 12 }}>
                  🎯 USE THIS PATTERN WHEN...
                </div>
                {pattern.when.map((w, i) => (
                  <div key={i} style={{
                    display: "flex",
                    alignItems: "flex-start",
                    gap: 10,
                    marginBottom: 8,
                    padding: "8px 12px",
                    background: "#111128",
                    borderRadius: 6,
                    fontSize: 13,
                    color: "#94a3b8"
                  }}>
                    <span style={{ color: pattern.color, flexShrink: 0, marginTop: 1 }}>▸</span>
                    {w}
                  </div>
                ))}
              </div>
            </div>
          )}

          {activeTab === "template" && (
            <div style={{
              background: "#060612",
              border: "1px solid #1e1e3f",
              borderRadius: 8,
              overflow: "hidden"
            }}>
              <div style={{
                display: "flex",
                justifyContent: "space-between",
                alignItems: "center",
                padding: "10px 16px",
                background: "#0d0d1a",
                borderBottom: "1px solid #1e1e3f"
              }}>
                <span style={{ fontSize: 11, color: "#475569" }}>C++ Template</span>
                <button
                  onClick={() => copyCode(pattern.template, activePattern)}
                  style={{
                    background: copiedIdx === activePattern ? pattern.color + "22" : "#111128",
                    border: `1px solid ${copiedIdx === activePattern ? pattern.color : "#2d2d4e"}`,
                    color: copiedIdx === activePattern ? pattern.color : "#64748b",
                    fontSize: 11,
                    padding: "4px 12px",
                    borderRadius: 4,
                    cursor: "pointer",
                    fontFamily: "inherit",
                    transition: "all 0.2s"
                  }}
                >
                  {copiedIdx === activePattern ? "✓ Copied!" : "Copy"}
                </button>
              </div>
              <pre style={{
                margin: 0,
                padding: "20px",
                fontSize: 12,
                lineHeight: 1.8,
                color: "#e2e8f0",
                overflowX: "auto",
                whiteSpace: "pre"
              }}>
                {pattern.template.split('\n').map((line, i) => {
                  const isComment = line.trim().startsWith('//');
                  const isKeyword = /\b(auto|int|long|vector|map|unordered_map|unordered_set|set|string|for|if|return|const|void)\b/.test(line);
                  return (
                    <div key={i} style={{ color: isComment ? "#475569" : "#e2e8f0" }}>
                      {line}
                    </div>
                  );
                })}
              </pre>
            </div>
          )}

          {activeTab === "problems" && (
            <div>
              <div style={{
                fontSize: 10, color: "#475569", fontWeight: 700,
                letterSpacing: "0.1em", marginBottom: 12
              }}>
                REAL CODEFORCES PROBLEMS — SORTED BY DIFFICULTY
              </div>
              {pattern.problems.map((prob, i) => (
                <div key={i} style={{
                  background: "#0d0d1a",
                  border: "1px solid #1e1e3f",
                  borderRadius: 8,
                  padding: "16px 20px",
                  marginBottom: 10,
                  transition: "border-color 0.15s"
                }}>
                  <div style={{ display: "flex", justifyContent: "space-between", alignItems: "flex-start", marginBottom: 8 }}>
                    <div>
                      <a
                        href={prob.link}
                        target="_blank"
                        rel="noopener noreferrer"
                        style={{
                          color: pattern.color,
                          textDecoration: "none",
                          fontSize: 14,
                          fontWeight: 600,
                          display: "inline-flex",
                          alignItems: "center",
                          gap: 6
                        }}
                      >
                        {prob.name}
                        <span style={{ fontSize: 10, opacity: 0.6 }}>↗</span>
                      </a>
                    </div>
                    <span style={{
                      background: "#1a1a3e",
                      border: "1px solid #3730a3",
                      color: "#818cf8",
                      fontSize: 11,
                      padding: "2px 10px",
                      borderRadius: 20,
                      flexShrink: 0,
                      marginLeft: 8
                    }}>
                      ★ {prob.rating}
                    </span>
                  </div>
                  <div style={{ display: "flex", alignItems: "flex-start", gap: 8 }}>
                    <span style={{ color: "#475569", fontSize: 14, flexShrink: 0 }}>→</span>
                    <p style={{ margin: 0, fontSize: 13, color: "#64748b", lineHeight: 1.6 }}>
                      {prob.explanation}
                    </p>
                  </div>
                </div>
              ))}
            </div>
          )}
        </div>
      </div>

      {/* Bottom: Common Pitfalls */}
      <div style={{ maxWidth: 1100, margin: "0 auto", padding: "0 32px 40px" }}>
        <div style={{
          background: "#0d0d1a",
          border: "1px solid #1e1e3f",
          borderRadius: 12,
          padding: "20px 24px"
        }}>
          <div style={{ fontSize: 10, color: "#f59e0b", fontWeight: 700, letterSpacing: "0.1em", marginBottom: 16 }}>
            ⚠️ COMMON PITFALLS & ANTI-HACKS
          </div>
          <div style={{ display: "grid", gridTemplateColumns: "repeat(auto-fit, minmax(280px, 1fr))", gap: 12 }}>
            {[
              { issue: "unordered_map getting hacked", fix: "Use custom hash or map<int,int> for CF. Anti-hash tests exploit default hash." },
              { issue: "String hash collisions", fix: "Use double hashing — two (BASE, MOD) pairs. Single hash fails on adversarial tests." },
              { issue: "Prefix sum overflow", fix: "Use long long. Sum of 10^5 elements each up to 10^9 = 10^14, exceeds int." },
              { issue: "Off-by-one in sliding window", fix: "When removing arr[i-k], make sure k matches your window definition exactly." },
              { issue: "Forgetting prefix_count[0] = 1", fix: "The empty prefix handles subarrays starting from index 0. Always init it." },
              { issue: "Compression not handling equal values", fix: "After sort, call unique() before lower_bound rank computation." }
            ].map((item, i) => (
              <div key={i} style={{
                background: "#111128",
                borderRadius: 8,
                padding: "12px 14px",
                borderLeft: "2px solid #f59e0b44"
              }}>
                <div style={{ fontSize: 12, fontWeight: 600, color: "#fbbf24", marginBottom: 4 }}>
                  ✗ {item.issue}
                </div>
                <div style={{ fontSize: 12, color: "#64748b", lineHeight: 1.5 }}>
                  ✓ {item.fix}
                </div>
              </div>
            ))}
          </div>
        </div>
      </div>
    </div>
  );
}
