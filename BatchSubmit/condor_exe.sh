PACKAGE=package.tar.gz
OUTPUTDIR=$1
OUTPUTFILENAME=$2
INPUTFILENAMES=$3
INDEX=$4
WEIGHTFILE=$5
SELECTION=$6
SCALE1FB=$7
TARGETLUMI=$8

echo "[wrapper] OUTPUTDIR       = " ${OUTPUTDIR}
echo "[wrapper] OUTPUTFILENAME  = " ${OUTPUTFILENAME}
echo "[wrapper] INPUTFILENAMES  = " ${INPUTFILENAMES}
echo "[wrapper] INDEX           = " ${INDEX}
echo "[wrapper] WEIGHTFILE           = " ${WEIGHTFILE}
echo "[wrapper] SELECTION           = " ${SELECTION}
echo "[wrapper] SCALE1FB           = " ${SCALE1FB}
echo "[wrapper] TARGETLUMI           = " ${TARGETLUMI}

echo "[wrapper] printing env"
printenv
echo 

echo "[wrapper] hostname  = " `hostname`
echo "[wrapper] date      = " `date`
echo "[wrapper] linux timestamp = " `date +%s`

######################
# Set up environment #
######################

# Untar
tar -xvf package.tar.gz

echo "[wrapper] running analyze now"
./analyze ${INPUTFILENAMES} ${OUTPUTFILENAMES} ${INDEX} ${WEIGHTFILE} ${SELECTION} ${SCALE1FB} ${TARGETLUMI}

echo "[wrapper] gfal-copy output file"
gfal-copy -p -f -t 4200 --verbose file://`pwd`/${OUTPUTFILENAME}_${INDEX}.root gsiftp://gftp.t2.ucsd.edu/${OUTPUTDIR}/${OUTPUTFILENAME}_${INDEX}.root --checksum ADLER32
