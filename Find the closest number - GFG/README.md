# Find the closest number
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of <strong>sorted</strong> integers. The task is to find the closest value to the given number in array. Array may contain duplicate values.</span></p>

<p><span style="font-size:18px"><strong>Note:</strong> If the difference is same for two values print the value which is greater than the given number.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> Arr[] = {1, 3, 6, 7} and K = 4
<strong>Output :</strong> 3
<strong>Explanation:
</strong>We have an array [1, 3, 6, 7] and target is 4.
If we look at the absolute difference of target 
with every element of an array we will 
get [ |1-4|, |3-4|, |6-4|, |7-4|&nbsp;]. 
So, the closest number is <strong>3.</strong>

</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> Arr[] = {1, 2, 3, 5, 6, 8, 9}, K = 4
<strong>Output :</strong> 5
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>findClosest()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, integer <strong>target</strong> and return the closest number of the target in an array. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(log(N)).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ K ≤ 10<sup>5</sup><br>
1 ≤ A[i] ≤ 10<sup>5</sup></span></p>
</div>