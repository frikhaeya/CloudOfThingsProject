
* Manage Deployments with the Atlas Administration API
https://docs.atlas.mongodb.com/api/atlas-admin-api/

* Geolocator 8.0.1
With Flutter:

 $ flutter pub add geolocator
This will add a line like this to your package's pubspec.yaml (and run an implicit flutter pub get):

dependencies:
  geolocator: ^8.0.1
Alternatively, your editor might support or flutter pub get. Check the docs for your editor to learn more.

Import it
Now in your Dart code, you can use:

import 'package:geolocator/geolocator.dart';
