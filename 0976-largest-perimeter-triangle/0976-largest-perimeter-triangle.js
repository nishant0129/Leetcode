/**
 * @param {number[]} nums
 * @return {number}
 */
var largestPerimeter = function(nums) {
    //let cmp=(a,b)=>{return b-a};
    nums.sort((a,b)=>{return b-a});
    
    for(let i=0; i<nums.length-2;i++)
    {
            if(nums[i]<nums[i+1]+nums[i+2])
                return nums[i]+nums[i+1]+nums[i+2];
    }
    return 0;
};