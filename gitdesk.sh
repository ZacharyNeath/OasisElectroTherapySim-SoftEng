#Script to get github desktop working on linux.
#Before running make sure you make this file executable permissions:
#go to the directory the file is in and type:
#chmod +rwx gitdesk.sh
#
#Now you can run the script with ./gitdesk.sh

#Installing Visual Studio:
#1. open terminal
#2. enter "sudo apt update"
#3. enter password
#4. enter "sudo apt install snapd"
#5. enter "sudo snap install code --classic"

#Script starts here
#Download key and mirror to be able to download packageds
sudo wget -qO - https://mirror.mwt.me/ghd/gpgkey | sudo tee /etc/apt/trusted.gpg.d/shiftkey-desktop.asc > /dev/null

#download packages
sudo sh -c 'echo "deb [arch=amd64] https://packagecloud.io/shiftkey/desktop/any/ any main" > /etc/apt/sources.list.d/packagecloud-shiftkey-desktop.list'

#Installation
sudo apt update && sudo apt install github-desktop
