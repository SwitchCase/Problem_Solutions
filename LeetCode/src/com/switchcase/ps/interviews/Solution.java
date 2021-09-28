package com.switchcase.ps.interviews;

import java.util.LinkedList;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

public class Solution {    // ############################ BEGIN Solution Classes ############################

    /**
     * NOTE: You are free to modify anything below, except for class names and generic interface.
     * Other public interface changes may require updating one or more of the helper classes above
     * for test cases to run and pass.
     * <p>
     * A Set-Associative Cache data structure with fixed capacity.
     * <p>
     * - Data is structured into setCount # of setSize-sized sets.
     * - Every possible key is associated with exactly one set via a hashing algorithm
     * - If more items are added to a set than it has capacity for (i.e. > setSize items),
     *      a replacement victim is chosen from that set using an LRU algorithm.
     * <p>
     * NOTE: Part of the exercise is to allow for different kinds of replacement algorithms...
     */
    public static class SetAssociativeCache<TKey, TValue> {
        int Capacity;
        int SetSize;
        int SetCount;
        CacheSet<TKey, TValue>[] Sets;


        public SetAssociativeCache(int setCount, int setSize, IReplacementAlgo<TKey> strategy) {
            this.SetCount = setCount;
            this.SetSize = setSize;
            this.Capacity = this.SetCount * this.SetSize;

            // Initialize the sets
            this.Sets = new CacheSet[this.SetCount];
            for (int i = 0; i < this.SetCount; i++) {
                //TODO: strategy needs to be initialized seperately per cache set.
                Sets[i] = new CacheSet<>(setSize, strategy);
            }
        }

        /** Gets the value associated with `key`. Throws if key not found. */
        public TValue get(TKey key) {
            int setIndex = this.getSetIndex(key);
            CacheSet<TKey, TValue> set = this.Sets[setIndex];
            return set.get(key);
        }

        /**
         * Adds the `key` to the cache with the associated value, or overwrites the existing key.
         * If adding would exceed capacity, an existing key is chosen to replace using an LRU algorithm
         * (NOTE: It is part of this exercise to allow for more replacement algos)
         */
        public void set(TKey key, TValue value) {
            int setIndex = this.getSetIndex(key);
            CacheSet<TKey, TValue> set = this.Sets[setIndex];
            set.set(key, value);
        }

        /** Returns the count of items in the cache */
        public int getCount() {
            int count = 0;
            for (int i = 0; i < this.Sets.length; i++) {
                count += this.Sets[i].count.get();
            }
            return count;
        }

        /** Maps a key to a set */
        private int getSetIndex(TKey key) {
            return Math.abs(key.hashCode()) % this.SetCount;
        }
    }

    /**
     * An internal data structure representing one set in a N-Way Set-Associative Cache
     */
    static class CacheSet<TKey, TValue> {
        int Capacity;
        Map<TKey, TValue> Store;
        public AtomicInteger count;
        IReplacementAlgo<TKey> replacementAlgo;

        public CacheSet(int capacity, IReplacementAlgo<TKey> replacementAlgo) {
            this.Capacity = capacity;
            this.Store = new ConcurrentHashMap<>();
            this.replacementAlgo = replacementAlgo;
        }

        /** Gets the value associated with `key`. Throws if key not found. */
        public synchronized TValue get(TKey key) {
            // If the key is present, update the usage tracker
            if (Store.containsKey(key)) {
                replacementAlgo.recordUsage(key);
            } else {
                throw new RuntimeException(String.format("The key '%s' was not found", key));
            }

            return Store.get(key);
        }

        /**
         * Adds the `key` to the cache with the associated value, or overwrites the existing key.
         * If adding would exceed capacity, an existing key is chosen to replace using an LRU algorithm
         * (NOTE: It is part of this exercise to allow for more replacement algos)
         */
        public synchronized void set(TKey key, TValue value) {

            if (Store.containsKey(key)) {
                Store.put(key, value);
            } else {
                // If the set is at it's capacity
                if (this.count.get() == this.Capacity) {
                    // Choose the Least-Recently-Used (LRU) item to replace, which will be at the tail of the usage tracker
                    // TODO: Factor this logic out to allow for custom replacement algos

                    TKey keyToReplace = this.replacementAlgo.getKeyToRemove(key);
                    Store.remove(keyToReplace);

                } else {
                    count.addAndGet(1);
                }
                Store.put(key, value);
            }
            replacementAlgo.recordUsage(key);
        }
    }

    /**
     * An internal data structure representing a single item in an N-Way Set-Associative Cache
     */
    static class CacheItem<TKey, TValue> {
        public TKey key;
        public TValue value;

        public CacheItem(TKey key, TValue value) {
            this.key = key;
            this.value = value;
        }
    }

    public final static String LruAlgorithm = "LRUReplacementAlgo";
    public final static String MruAlgorithm = "MRUReplacementAlgo";



    /**
     * A common interface for replacement algos, which decide which item in a CacheSet to evict
     */
    interface IReplacementAlgo<TKey> {
        void recordUsage(TKey key);

        TKey getKeyToRemove(TKey newKey);

    }

    class LRUReplacementAlgo<TKey> implements IReplacementAlgo<TKey> {

        private final LinkedList<TKey> linkedList;

        private final int capacity;

        LRUReplacementAlgo(int capacity) {
            this.capacity = capacity;
            this.linkedList = new LinkedList<>();
        }

        //runs in O(N). want it O(1).
        @Override
        public synchronized void recordUsage(TKey inKey) {
            int idx = linkedList.indexOf(inKey);
            linkedList.remove(idx);
            linkedList.addFirst(inKey);
        }

        @Override
        public synchronized TKey getKeyToRemove(TKey newKey) {
            if (linkedList.isEmpty()) {
                return null;
            }
            return linkedList.getLast();
        }

        // TODO: Implement the interface defined above
    }

    class MRUReplacementAlgo implements IReplacementAlgo {
        @Override
        public void recordUsage(Object o) {

        }

        @Override
        public Object getKeyToRemove(Object newKey) {
            return null;
        }

        // TODO: Implement the interface defined above
    }

    // ############################ BEGIN Helper Classes ############################
    // NOTE: Your code in the classes below will not be evaluated as part of the exericse.
    // They are just used by the stub code in the header to help run HackerRank test cases.
    // You may need to make small modifications to these classes, depending on your interface design,
    // for tests to run and pass, but it is not a core part of the exercise
    //
    static class OutParam<T> {
        public T value;
    }

    private static boolean isNullOrEmpty(String s) {
        return s == null || s.isEmpty();
    }}