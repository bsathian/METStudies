import os

# check for files smaller than x bytes
os.system("du -a /hadoop/cms/store/user/smay/MET/* | awk '$1*512 < 2000 {print $2} ' > bad_files.txt")

with open ("bad_files.txt") as fin:
  for line in fin:
    print("Removing file %s" % line)
    os.system("rm %s" % line)
