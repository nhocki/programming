n = STDIN.gets
nums = STDIN.gets.split(" ")

def possible(energy, nums)
  nums.each do |n|
    energy -= (n.to_i - energy)
    return false if energy < 0
  end
  return energy >= 0
end

hi = 10**5 + 100
lo = 0

while lo < hi do
  mid = lo + (hi - lo) / 2
  if possible(mid, nums)
    hi = mid
  else
    lo = mid + 1
  end
end

STDOUT.puts(lo)

