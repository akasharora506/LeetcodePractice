class Solution {
    public int longestConsecutive(int[] nums) {
       PriorityQueue<Integer> pq=new PriorityQueue<>();
        for(int i=0;i<nums.length;i++){
            pq.add(nums[i]);
        }
        int max=!pq.isEmpty()?1:0;
        int x=pq.isEmpty() ? 0 : pq.poll();
        while(!pq.isEmpty()){
            int c=1;
            while(!pq.isEmpty() && (pq.peek()==x+1 || pq.peek()==x)){
                if(pq.peek()==x+1)c++;
                max=Math.max(c,max);
                    x=pq.poll();
            }
            if(!pq.isEmpty())x=pq.poll();
            
            
        }
        return max;
        
    }
    // 0 1 1 2
}