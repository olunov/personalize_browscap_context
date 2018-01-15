INTRODUCTION
------------
This module provides personalize contexts based on browscap data. The
available browscap properties are:
 * Browser (IE, Chrome, Firefox, etc.)
 * Platform (Win7, Win10, iOS, Android, Linux, etc. )
 * Is Mobile Device
 * Is Tablet
 * Device Type (Desktop, Console, Mobile Device, Tablet, etc.)
Based on the options for each of these contexts it is possible to use
them to define when personalized content will be shown. Learn more about
personalization in README.txt and project page of personalize module.

REQUIREMENTS
------------
This module requires the following module(s):
 * Browscap (https://www.drupal.org/project/browscap)
 * Personalize (https://www.drupal.org/project/personalize)


INSTALLATION
------------
 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.
 * Go to admin/config/system/browscap, configure updating browscap data
   and run importing. For more details see README.txt in browscap module.
 * Go to admin/config/content/personalize/browscap and specify which
   context options should be available for managing personalization. For
   example you can mark only few most popular browsers (like Chrome,
   Firefox, IE, etc.). You can leave them by default, but in this case
   whole list with all of available options will be shown on page for
   managing personalization.
 * Manage personalization on admin/structure/personalize. For more details
   see README.txt in personalize module.

 MAINTAINERS
-----------
Current maintainers:
 * Oleksandr Lunov (alunyov) - https://www.drupal.org/user/103985
