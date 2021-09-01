class Solution {
    public int findPeakElement(int[] nums) {
        int max=Integer.MIN_VALUE;
      TreeMap<Integer,Integer>map=new TreeMap<>();
      for(int i=0;i<nums.length;i++)
      {
         if(!map.containsKey(nums[i]))
         {
           max=Math.max(max,nums[i]);
           map.put(nums[i],i);
         }
        
      }
      return map.get(max);
    
    }
}