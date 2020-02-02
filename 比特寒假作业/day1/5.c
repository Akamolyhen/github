class Solution{
	public void rotate(int[] nums,int k){
	int temp;
	int n=sizeof(nums)/sizeof(int);
	for(int i=1;i<=k;i++){
	temp=nums[n-1];
	for(int j=0;j<n-1;j++){
	nums[n-1-j]=nums[n-2-j];
	}
	nums[0]=temp;
	}
	}
};