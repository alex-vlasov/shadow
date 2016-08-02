#!/bin/bash

phpver=$(phpenv version | cut -f 1 -d ' ')
echo "PHP version reported by phpenv is: $phpver"
case $phpver in
  5.4|5.4.*)
    # Oh goody, stupidly old PHP version. Here comes some fun.
    sudo add-apt-repository -y ppa:ondrej/php5-oldstable
    sudo apt-get update
    sudo apt-get -y install php5-dev php5-cli
    # The packages for 12.04 use dpkg-query in a broken way. Fix the script
    # so that when we call it to find what SAPIs are present, it doesn't
    # just shrug its shoulders at us.
    sudo sed -i.stock -r -e 's/\$\{binary:Package\}/${Package}/' \
        /usr/bin/php-config5
    # Use the PHP system packages, since we just, you know, went to the
    # trouble of installing ones that aren't total crap.
    phpenv global system
    ;;
  5.5|5.5.*)
    # Slightly less painfully old PHP version.
    sudo add-apt-repository -y ppa:ondrej/php
    sudo apt-get update
    sudo apt-get -y install php5.5-dev php5.5-cli

    # The packages for 12.04 use dpkg-query in a broken way. Fix the script
    # so that when we call it to find what SAPIs are present, it doesn't
    # just shrug its shoulders at us.
    sudo sed -i.stock -r -e 's/\$\{binary:Package\}/${Package}/' \
        /usr/bin/php-config5.5
    phpenv global system
    ;;
  5.6|5.6.*)
    sudo add-apt-repository -y ppa:ondrej/php
    sudo apt-get update
    sudo apt-get install php5.6-dev php5.6-cli

    # The packages for 12.04 use dpkg-query in a broken way. Fix the script
    # so that when we call it to find what SAPIs are present, it doesn't
    # just shrug its shoulders at us.
    sudo sed -i.stock -r -e 's/\$\{binary:Package\}/${Package}/' \
        /usr/bin/php-config5.6
    phpenv global system
    ;;
  7.0|7.0.*)
    sudo add-apt-repository -y ppa:ondrej/php
    sudo apt-get update
    sudo apt-get install php7.0-dev php7.0-cli

    # The packages for 12.04 use dpkg-query in a broken way. Fix the script
    # so that when we call it to find what SAPIs are present, it doesn't
    # just shrug its shoulders at us.
    sudo sed -i.stock -r -e 's/\$\{binary:Package\}/${Package}/' \
        /usr/bin/php-config7.0
    phpenv global system
    ;;
  *)
    echo "Fool, I don't know anything about that PHP version."
    exit 1
    ;;
esac

