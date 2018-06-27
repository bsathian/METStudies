import os
import glob

# check for files smaller than x bytes
os.system("du -a /hadoop/cms/store/user/smay/MET/* | awk '$1*512 < 2000 {print $2} ' > bad_files.txt")

with open ("bad_files.txt") as fin:
  for line in fin:
    print("Removing file %s" % line)
    os.system("rm %s" % line)


# check for corrupt CMS4 files
def find_corrupt_files(paths):
  corruptions = "corruptions.txt"

  os.system("touch %s" % corruptions)
  os.system("rm %s" % corruptions)
  for path in paths:
    os.system("hdfs fsck %s >> %s" % (path.replace("/hadoop",""), corruptions))

  fnames = []
  with open(corruptions, "r") as fhin:
      for line in fhin:
          if "CORRUPT" not in line: continue
          if ".root" not in line: continue
          fname = line.split()[0].replace(":","")
          fnames.append("/hadoop"+fname)
  return fnames

#path = "/hadoop/cms/store/user/smay/ProjectMetis/"
#corrupt_files = find_corrupt_files(path)
#for file in corrupt_files:
#  print("Files %s is corrupt, removing it" % file)
  #os.system("rm %s" %file)
