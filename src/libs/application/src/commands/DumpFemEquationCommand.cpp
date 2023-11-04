#include <application/commands/DumpFemEquationCommand.hpp>

// Qt includes
#include <QDebug>
#include <QFile>

gui::application::DumpFemEquationCommand::DumpFemEquationCommand(fem::AnalysisResult& result, QString file_name) : result(result), file_name(file_name) {}

void gui::application::DumpFemEquationCommand::execute() {
	qInfo() << "MainWindow::dumpEquation()";

	// check if file already exists
	QFile file;
	file.setFileName(file_name);

	// set a new file name for this file

	file.open(QFile::WriteOnly);
	QTextStream out(&file);
	out.setRealNumberNotation(QTextStream::ScientificNotation);
	out.setRealNumberPrecision(16);

	out << "# Created by lalib\n";
	out << "# name: K\n";
	out << "# type: matrix\n";
	out << "# rows: " << result.equation.K.rows() << "\n";
	out << "# columns: " << result.equation.K.columns() << "\n";

	for (size_t j = 0; j < result.equation.K.columns(); j++) {
		for (size_t i = 0; i < result.equation.K.rows(); i++) {
			out << " " << result.equation.K.value(i, j);
		}
		out << "\n";
	}
	out << Qt::endl;

	out << "# Created by lalib\n";
	out << "# name: f\n";
	out << "# type: matrix\n";
	out << "# rows: " << result.equation.size() << "\n";
	out << "# columns: 1\n";

	for (size_t i = 0; i < result.equation.size(); i++) {
		out << " " << result.equation.f.value(i) << "\n";
	}
	out << Qt::endl;

	out << "# Created by lalib\n";
	out << "# name: d\n";
	out << "# type: matrix\n";
	out << "# rows: " << result.equation.d.size() << "\n";
	out << "# columns: 1\n";

	for (size_t i = 0; i < result.equation.d.size(); i++) {
		out << " " << result.equation.d.value(i) << "\n";
	}

	out << Qt::endl;
	file.close();
}