import 'package:flutter/material.dart';
import 'package:player/example/example.dart';

void main() => runApp(MaterialApp(
      home: Home(),
    ));

class Home extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return SamplePlayer();
  }
}
